#include "PointLight.h"

RGB PointLight::illuminate(const HitRecord& record) const {
    return RGB();
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
