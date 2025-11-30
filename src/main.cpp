#include "Sphere/Sphere.h"
#include "Camera/Camera.h"
#include "Vector3/Vector3.h"
#include "Image/Image.h"
#include "RGB/RGB.h"
#include "SurfaceGroup/SurfaceGroup.h"
#include "Renderer/Renderer.h"
#include "AmbientLight/AmbientLight.h"
#include "Scene/Scene.h"
#include "Triangle/Triangle.h"
#include "PointLight/PointLight.h"
#include "SpecularMaterial/SpecularMaterial.h"

int main(int argc, char* argv[]) {
    float nx = 1420;
    float ny = 1080;
    Image img(nx, ny);

    Scene s;
    s.color = RGB(0.4f, 0.6f, 0.9f);

    AmbientLight al;
    float ambient_light_intensity = 0.6f;
    al.set_intensity(RGB(ambient_light_intensity, ambient_light_intensity, ambient_light_intensity));
    s.lights.push_back(&al);

    PointLight pl;
    float pl_intensity = 1.0f;
    pl.set_intensity(RGB(pl_intensity, pl_intensity, pl_intensity));
    pl.set_position(Vector3(-1.0f, 2.0f, 1.0f));
    s.lights.push_back(&pl);

    float h = 2;
    float w = nx / ny * h;
    float focal_length = 1;
    Vector3 camera_origin(0, 3, 0);
    Camera cam(focal_length, w, h, camera_origin, Vector3(0, 0, 0));
    cam.set_type(OBLIQUE);

    // --- MATERIAL 1: RED PLASTIC ---
    SpecularMaterial* material1 = new SpecularMaterial();
    material1->set_phong_exponent(100);
    material1->set_specular_coefficient(RGB(0.5f, 0.5f, 0.5f));
    material1->color = RGB(0.8f, 0.1f, 0.1f);

    // --- MATERIAL 2: WHITE FLOOR ---
    SpecularMaterial* material2 = new SpecularMaterial();
    material2->set_phong_exponent(10);
    material2->set_specular_coefficient(RGB(0.6f, 0.6f, 0.6f));
    material2->color = RGB(0.85f, 0.75f, 0.6f);

    // --- NEW MATERIAL 3: SHINY BLUE ---
    SpecularMaterial* material3 = new SpecularMaterial();
    material3->set_phong_exponent(50);
    material3->set_specular_coefficient(RGB(0.6f, 0.6f, 0.6f));
    material3->color = RGB(0.1f, 0.2f, 0.9f);

    // Ball 1 (Red)
    Sphere green_ball(-0.5, 0.5, 0, 0.5);
    green_ball.mat = material1;

    // Ball 2 (Blue)
    Sphere blue_ball(-1.2f, 0.5f, 0.5f, 0.5f); 
    blue_ball.mat = material3;

    // Ground
    Triangle ground_plane;
    ground_plane.set_a(Vector3(-1000.0f, 0.0f, 1000.0f));
    ground_plane.set_b(Vector3(1000.0f, 0.0f, 1000.0f));
    ground_plane.set_c(Vector3(-1000.0f, 0.0f, -1000.0f));
    ground_plane.mat = material2;

    SurfaceGroup group;
    group.add_object(&green_ball);
    group.add_object(&blue_ball);
    group.add_object(&ground_plane);
    
    cam.set_target(green_ball.get_center());

    Renderer r;
    s.cam = &cam;
    s.group = &group;

    r.render(s, cam, img);

    // Cleanup
    delete material1;
    delete material2;
    delete material3;

    img.save_ppm("test.ppm");
    return 0;
}
