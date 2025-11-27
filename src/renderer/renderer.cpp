#include "renderer.h"

void renderer::render(const surface_group& scene, const camera& cam, image& img) const {
    float nx = img.get_width();
    float ny = img.get_height();
    float l = -cam.get_width() / 2;
    float r = cam.get_width() / 2;
    float t = cam.get_height() / 2;
    float b = -cam.get_height() / 2;

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            float u = l + (r - l) * (i + 0.5) / nx;
            float v = b + (t - b) * (1 - (j + 0.5) / ny);
            ray* r = cam.get_ray(u, v);
            rgb pixel_color = trace_ray(r, scene);
            img.set_pixel_at(i, j, pixel_color);
            delete r;
        }
    }
}

rgb renderer::trace_ray(const ray* r, const surface_group& group) const {
    hit_record* record = new hit_record();
    group.hit(r, record);
    rgb color(0, 0, 0);
    if (record->hit_point < std::numeric_limits<float>::max()) {
        color = record->s->color;
    }
    delete record;
    return color;
}
