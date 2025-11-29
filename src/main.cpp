#include "sphere/sphere.h"
#include "camera/camera.h"
#include "vector3/vector3.h"
#include "image/image.h"
#include "rgb/rgb.h"
#include "surface_group/surface_group.h"
#include "renderer/renderer.h"
#include "material/material.h"
#include "ambient_light/ambient_light.h"
#include "scene/scene.h"
#include "triangle/triangle.h"

int main(int argc, char* argv[]) {
    float nx = 1420;
    float ny = 1080;
    // create a new image of width nx, and height ny
    image img(nx, ny);

    // create the main scene
    scene s;
    s.color = rgb(64.0f/255.0f, 64.0f/255.0f, 64.0f/255.0f);

    // create the ambient light
    ambient_light al;
    al.set_color(rgb(0.5, 1, 0));

    float h = 2;
    float w = nx / ny * h;
    float focal_length = 1;
    vector3 camera_origin(0, 2, 0);
    // create a camera with focal_length=1, viewport width=w, viewport height=h
    // and at origin camera_origin
    camera cam(focal_length, w, h, camera_origin, vector3(0, 0, 0));
    cam.set_type(OBLIQUE);

    // create a green material
    material* material1 = new material();
    material1->color = rgb(0, 1, 0);

    // create a red material
    material* material2 = new material();
    material2->color = rgb(1, 0, 0);

    // create a simple ball
    sphere green_ball(-0.5, 0, 0, 0.5);
    // set the ball's material
    green_ball.mat = material1;

    // create another ball
    triangle red_triangle;
    red_triangle.set_a(vector3(0.0f, 0.0f, -1.0f));
    red_triangle.set_b(vector3(1.0f, 0.0f, -1.0f));
    red_triangle.set_c(vector3(0.0f, 1.0f, -1.0f)); // set the ball's material
    red_triangle.mat = material2;

    // create a group of surfaces and add all the balls and the sphere to it
    surface_group group;
    group.add_object(&green_ball);
    group.add_object(&red_triangle);
    // set the target of the camera to the green ball
    cam.set_target(green_ball.get_center());

    // create the renderer
    renderer r;

    // add the main objects to the scene
    s.cam = &cam;
    s.group = &group;
    s.lights.push_back(&al);

    // execute the render operation on the group, camera, and plot it on image img
    r.render(s, cam, img);

    // free the materials from the heap
    delete material1;
    delete material2;

    // save the image
    img.save_ppm("test.ppm");
    return 0;
}
