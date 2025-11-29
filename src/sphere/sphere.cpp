#include "sphere.h"

sphere::sphere() {
    radius = 0;
}

sphere::sphere(const float& x, const float& y, const float& z, const float& r) {
    center[0] = x;
    center[1] = y;
    center[2] = z;
    radius = r;
}

sphere::sphere(const vector3& center, const float& r) {
    radius = r;
    this->center = center;
}

void sphere::move_to(const float& x, const float& y, const float& z) {
    center[0] = x;
    center[1] = y;
    center[2] = z;
}

void sphere::move_to(const vector3& center) {
    this->center = center;
}

float sphere::get_radius() const {
    return radius;
}

void sphere::set_radius(const float& radius) {
    this->radius = radius;
}

void sphere::hit(const ray* r, hit_record*& record) const {
    record->s = this;
    const vector3 d = r->get_direction();
    const vector3 e = r->get_origin();
    float discriminant = std::pow(d.dot(e - center), 2) - (d.dot(d)) * ((e - center).dot(e - center) - std::pow(radius, 2));
    float t0, t1;
    if (discriminant < 0) {
        t0 = std::numeric_limits<float>::max();
        t1 = std::numeric_limits<float>::max();
    } else {
        t0 = (-d.dot(e - center) + std::sqrt(discriminant)) / d.dot(d);
        t1 = (-d.dot(e - center) - std::sqrt(discriminant)) / d.dot(d);
    }
    if (t1 > 0) {
        record->hit_distance = t1;
        record->hit_point = r->evaluate(t1);
    } else if (t0 > 0) {
        record->hit_distance = t0;
        record->hit_point = r->evaluate(t0);
    } else {
        record->hit_distance = std::numeric_limits<float>::max();
    }
}

const vector3& sphere::get_center() const {
    return center;
}

void sphere::get_normal(hit_record*& record) const {
    record->n = record->hit_point - center;
    record->n = record->n / record->n.magnitude();
}
