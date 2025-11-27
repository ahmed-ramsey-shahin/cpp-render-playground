#include "sphere/sphere.h"
#include "camera/camera.h"
#include "surface/surface.h"
#include "vector3/vector3.h"
#include "image/image.h"
#include "ray/ray.h"
#include "rgb/rgb.h"
#include "hit_record/hit_record.h"
#include "surface_group/surface_group.h"

int main(int argc, char* argv[]) {
    float w = 2.6296;
    float h = 2;
    float l = -w / 2;
    float r = w / 2;
    float t = h / 2;
    float b = -h / 2;
    float nx = 1420;
    float ny = 1080;
    image img(nx, ny);

    surface_group group;
    sphere space(0, 0, 0, 100);
    sphere green_ball(-1, 0, 0, 0.1);
    sphere red_ball(-2, 0, 0, 0.5);
    group.add_object(&green_ball);
    group.add_object(&red_ball);
    group.add_object(&space);
    green_ball.color = rgb(0, 255, 0);
    red_ball.color = rgb(255, 0, 0);
    space.color = rgb(64, 64, 64);

    vector3 camera_origin(0, 2, 0);
    camera cam(1, w, h, camera_origin, green_ball.get_center());
    hit_record* record = new hit_record();

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            float u = l + (r - l) * (i + 0.5) / nx;
            float v = b + (t - b) * (1 - (j + 0.5) / ny);
            ray* r = cam.get_ray(u, v);
            group.hit(r, record);
            if (record->hit_point < std::numeric_limits<float>::max()) {
                img.set_pixel_at(i, j, record->s->color);
            }
            delete r;
        }
    }

    delete record;
    img.save_ppm("test.ppm");
    return 0;
}
