#include "Sphere.h"

Sphere::Sphere() {
    radius = 0;
}

Sphere::Sphere(const float& x, const float& y, const float& z, const float& r) {
    center[0] = x;
    center[1] = y;
    center[2] = z;
    radius = r;
}

Sphere::Sphere(const Vector3& center, const float& r) {
    radius = r;
    this->center = center;
}

void Sphere::move_to(const float& x, const float& y, const float& z) {
    center[0] = x;
    center[1] = y;
    center[2] = z;
}

void Sphere::move_to(const Vector3& center) {
    this->center = center;
}

float Sphere::get_radius() const {
    return radius;
}

void Sphere::set_radius(const float& radius) {
    this->radius = radius;
}

bool Sphere::hit(const Ray* r, HitRecord*& record) const {
    if (record != nullptr)
        record->s = this;
    const Vector3 d = r->get_direction();
    const Vector3 e = r->get_origin();
    float discriminant = std::pow(d.dot(e - center), 2) - (d.dot(d)) * ((e - center).dot(e - center) - std::pow(radius, 2));
    float t0, t1;
    if (discriminant < 0) {
        t0 = std::numeric_limits<float>::max();
        t1 = std::numeric_limits<float>::max();
    } else {
        t0 = (-d.dot(e - center) + std::sqrt(discriminant)) / d.dot(d);
        t1 = (-d.dot(e - center) - std::sqrt(discriminant)) / d.dot(d);
    }
    if (t1 > 0 && t1 < std::numeric_limits<float>::max()) {
        if (record != nullptr) {
            record->hit_distance = t1;
            record->hit_point = r->evaluate(t1);
            get_normal(record);
        }
        return true;
    } else if (t0 > 0 && t1 < std::numeric_limits<float>::max()) {
        if (record != nullptr) {
            record->hit_distance = t0;
            record->hit_point = r->evaluate(t0);
            get_normal(record);
        }
        return true;
    } else {
        if (record != nullptr)
            record->hit_distance = std::numeric_limits<float>::max();
        return false;
    }
}

const Vector3& Sphere::get_center() const {
    return center;
}

void Sphere::get_normal(HitRecord*& record) const {
    record->n = record->hit_point - center;
    record->n = record->n / record->n.magnitude();
}
