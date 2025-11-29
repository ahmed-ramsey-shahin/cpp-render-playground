#include "PointLight.h"

RGB PointLight::illuminate(const Ray* r, const HitRecord& record) const {
    float rr = (p - record.hit_point).magnitude();
    Vector3 l = (p - record.hit_point) / rr;
    Vector3 n = record.n;
    RGB e = (intensity / std::pow(rr, 2)) * std::max(0.0f, n.dot(l));
    RGB k = record.s->mat->evaluate(l, r->get_direction() / r->get_direction().magnitude(), n);
    return RGB(e[0]*k[0], e[1]*k[1], e[2]*k[2]);
}

void PointLight::set_position(const Vector3& p) {
    this->p = p;
}
const Vector3& PointLight::get_position() const {
    return p;
}

void PointLight::set_intensity(const RGB& intensity) {
    this->intensity = intensity;
}
const RGB& PointLight::get_intensity() const {
    return this->intensity;
}
