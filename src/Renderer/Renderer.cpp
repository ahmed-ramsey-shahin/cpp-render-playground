#include "Renderer.h"

void Renderer::render(const Scene& s, const Camera& cam, Image& img) const {
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
            Ray* r = cam.get_ray(u, v);
            RGB pixel_color = trace_ray(r, s);
            img.set_pixel_at(i, j, pixel_color);
            delete r;
        }
    }
}

RGB Renderer::trace_ray(const Ray* r, const Scene& s) const {
    HitRecord* record = new HitRecord();
    s.group->hit(r, record);
    RGB color(0, 0, 0);
    if (record->hit_distance < std::numeric_limits<float>::max()) {
        record->s->get_normal(record);
        for (const Light* x : s.lights) {
            color = color + x->illuminate(r, *record);
        }
    } else {
        color = s.color;
    }
    delete record;
    return color;
}
