#include "sphere/sphere.h"
#include "camera/camera.h"
#include "vector3/vector3.h"
#include "image/image.h"
#include "rgb/rgb.h"
#include "surface_group/surface_group.h"
#include "renderer/renderer.h"
#include "material/material.h"

int main(int argc, char* argv[]) {
    float nx = 1420;
    float ny = 1080;
    image img(nx, ny); // create a new image of width nx, and height ny

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
    material1->color = rgb(0, 255, 0);

    // create a red material
    material* material2 = new material();
    material2->color = rgb(255, 0, 0);

    // create a grey material
    material* material3 = new material();
    material3->color = rgb(64, 64, 64);

    // create the sphere which represents the world
    sphere space(0, 0, 0, 100);
    // set the sphere's material to material3
    space.mat = material3;

    // create a simple ball
    sphere green_ball(-0.5, 0, 0, 0.5);
    // set the ball's material
    green_ball.mat = material1;

    // create another ball
    sphere red_ball(-0.75, 0, 1.25, 0.5);
    // set the ball's material
    red_ball.mat = material2;

    // create a group of surfaces and add all the balls and the sphere to it
    surface_group group;
    group.add_object(&green_ball);
    group.add_object(&red_ball);
    group.add_object(&space);
    // set the target of the camera to the green ball
    cam.set_target(green_ball.get_center());
    // create the renderer
    renderer r;
    // execute the render operation on the group, camera, and plot it on image img
    r.render(group, cam, img);

    // free the materials from the heap
    delete material1;
    delete material2;
    delete material3;

    // save the image
    img.save_ppm("test.ppm");
    return 0;
}
