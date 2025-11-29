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

RGB DirectionalLight::illuminate(LightRecord& record) const {
    record.light_direction = -direction;
    return intensity * record.surface_normal.dot(record.light_direction);
}

Vector3 DirectionalLight::get_direction(const Vector3& x) const {
    return direction;
}
