#include "PointLight.h"

RGB PointLight::illuminate(const HitRecord& record) const {
    Vector3 light_direction = position - record.hit_point;
    return intensity * record.n.dot(light_direction) / std::pow(record.hit_distance, 2);
}

void PointLight::set_position(const Vector3& position) {
    this->position = position;
}
const Vector3& PointLight::get_position() const {
    return position;
}

void PointLight::set_intensity(const RGB& intensity) {
    this->intensity = intensity;
}
const RGB& PointLight::get_intensity() const {
    return this->intensity;
}
