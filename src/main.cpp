#include "sphere/sphere.h"
#include "camera/camera.h"
#include "vector3/vector3.h"
#include "image/image.h"
#include "rgb/rgb.h"
#include "surface_group/surface_group.h"
#include "renderer/renderer.h"

int main(int argc, char* argv[]) {
    float nx = 1420;
    float ny = 1080;
    image img(nx, ny);

    float h = 2;
    float w = nx / ny * h;
    float focal_length = 1;
    vector3 camera_origin(0, 2, 0);
    camera cam(focal_length, w, h, camera_origin, vector3(0, 0, 0));
    cam.set_type(OBLIQUE);

    sphere space(0, 0, 0, 100);
    space.color = rgb(64, 64, 64);

    sphere green_ball(-0.5, 0, 0, 0.5);
    green_ball.color = rgb(0, 255, 0);

    sphere red_ball(-0.75, 0, 1.25, 0.5);
    red_ball.color = rgb(255, 0, 0);

    surface_group group;
    group.add_object(&green_ball);
    group.add_object(&red_ball);
    group.add_object(&space);

    cam.set_target(green_ball.get_center());
    renderer r;
    r.render(group, cam, img);

    img.save_ppm("test.ppm");
    return 0;
}
