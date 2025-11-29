#include "PointLight.h"

RGB PointLight::illuminate(LightRecord& record) const {
    record.light_direction = position - record.hit_point;
    record.light_distance = (position - record.hit_point).magnitude();
    return intensity * record.surface_normal.dot(record.light_direction) / std::pow(record.light_distance, 2);
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

Vector3 PointLight::get_direction(const Vector3& x) const {
    return position - x;
}
