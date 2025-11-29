#include "DirectionalLight.h"

const RGB& DirectionalLight::get_intensity() const {
    return intensity;
}

void DirectionalLight::set_intensity(const RGB& intensity) {
    this->intensity = intensity;
}

const Vector3& DirectionalLight::get_direction() const {
    return direction;
}

void DirectionalLight::set_direction(const Vector3& direction) {
    this->direction = direction;
}

RGB DirectionalLight::illuminate(const HitRecord& record) const {
    return RGB();
}
