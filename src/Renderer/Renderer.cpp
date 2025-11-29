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
        for (const Light* light : s.lights) {
            LightRecord* light_record = trace_light(s.group, light, record);
            if (light_record != nullptr) {
                light_record->view_direction = -r->get_direction();
                RGB intensity = light->illuminate(*light_record);
                RGB brdf = record->s->mat->evaluate(
                    light_record->light_direction,
                    light_record->surface_normal,
                    light_record->view_direction
                );
                color = color + intensity * brdf;
            }
            delete light_record;
        }
    } else {
        color = s.color;
    }
    delete record;
    return color;
}

LightRecord* Renderer::trace_light(const SurfaceGroup* group, const Light* light, const HitRecord* record) const {
    Vector3 light_direction = light->get_direction(record->hit_point);
    Ray ray(
        record->hit_point + record->n * std::pow(10, -4),
        light_direction
    );
    LightRecord* light_record = new LightRecord();
    HitRecord* empty_record = nullptr;
    if (!group->hit(&ray, empty_record)) {
        light_record->surface_normal = record->n;
        light_record->hit_point = record->hit_point;
        return light_record;
    }
    return nullptr;
}
