#include "Sphere/Sphere.h"
#include "Camera/Camera.h"
#include "Vector3/Vector3.h"
#include "Image/Image.h"
#include "RGB/RGB.h"
#include "SurfaceGroup/SurfaceGroup.h"
#include "Renderer/Renderer.h"
#include "IdealDiffuseMaterial/IdealDiffuseMaterial.h"
#include "AmbientLight/AmbientLight.h"
#include "Scene/Scene.h"
#include "Triangle/Triangle.h"
#include "PointLight/PointLight.h"
#include "SpecularMaterial/SpecularMaterial.h"

int main(int argc, char* argv[]) {
    float nx = 1420;
    float ny = 1080;
    // create a new image of width nx, and height ny
    Image img(nx, ny);

    // create the main scene
    Scene s;
    s.color = RGB(64.0f/255.0f, 64.0f/255.0f, 64.0f/255.0f);

    // create the ambient light
    AmbientLight al;
    float ambient_light_intensity = 0.6f;
    al.set_intensity(RGB(ambient_light_intensity, ambient_light_intensity, ambient_light_intensity));
    s.lights.push_back(&al);

    // create the point light
    PointLight pl;
    float pl_intensity = 1.0f;
    pl.set_intensity(RGB(pl_intensity, pl_intensity, pl_intensity));
    pl.set_position(Vector3(-1.0f, 2.0f, 1.0f));
    s.lights.push_back(&pl);

    float h = 2;
    float w = nx / ny * h;
    float focal_length = 1;
    Vector3 camera_origin(0, 2, 0);
    // create a camera with focal_length=1, viewport width=w, viewport height=h
    // and at origin camera_origin
    Camera cam(focal_length, w, h, camera_origin, Vector3(0, 0, 0));
    cam.set_type(OBLIQUE);

    // create a green material
    SpecularMaterial* material1 = new SpecularMaterial();
    material1->set_phong_exponent(100);
    material1->set_specular_coefficient(RGB(0.5f, 0.5f, 0.5f));
    material1->color = RGB(0.8f, 0.1f, 0.1f);

    // create a red material
    IdealDiffuseMaterial* material2 = new IdealDiffuseMaterial();
    material2->color = RGB(1, 1, 1);

    // create a simple ball
    Sphere green_ball(-0.5, 0.5, 0, 0.5);
    // set the ball's material
    green_ball.mat = material1;

    // create another ball
    Triangle ground_plane;
    ground_plane.set_a(Vector3(-1000.0f, 0.0f, 1000.0f));
    ground_plane.set_b(Vector3(1000.0f, 0.0f, 1000.0f));
    ground_plane.set_c(Vector3(-1000.0f, 0.0f, -1000.0f)); // set the ball's material
    ground_plane.mat = material2;

    // create a group of surfaces and add all the balls and the sphere to it
    SurfaceGroup group;
    group.add_object(&green_ball);
    group.add_object(&ground_plane);
    // set the target of the Camera to the green ball
    cam.set_target(green_ball.get_center());

    // create the renderer
    Renderer r;

    // add the main objects to the scene
    s.cam = &cam;
    s.group = &group;

    // execute the render operation on the group, Camera, and plot it on image img
    r.render(s, cam, img);

    // free the materials from the heap
    delete material1;
    delete material2;

    // save the image
    img.save_ppm("test.ppm");
    return 0;
}
