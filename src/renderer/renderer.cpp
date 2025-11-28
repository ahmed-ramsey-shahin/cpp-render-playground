#include "renderer.h"

void renderer::render(const scene& s, const camera& cam, image& img) const {
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
            rgb pixel_color = trace_ray(r, s);
            img.set_pixel_at(i, j, pixel_color);
            delete r;
        }
    }
}

rgb renderer::trace_ray(const ray* r, const scene& s) const {
    hit_record* record = new hit_record();
    s.group->hit(r, record);
    rgb color(0, 0, 0);
    if (record->hit_point < std::numeric_limits<float>::max()) {
        for (const light* x : s.lights) {
            color = color + x->illuminate(r, *record);
        }
    } else {
        color = s.color;
    }
    delete record;
    return color;
}
