#include "AmbientLight.h"

void AmbientLight::set_intensity(const RGB& intensity) {
    this->intensity = intensity;
}
const RGB& AmbientLight::get_intensity() const {
    return intensity;
}

RGB AmbientLight::illuminate(LightRecord& record) const {
    record.light_direction = Vector3();
    record.light_distance = 0;
    return intensity;
}

Vector3 AmbientLight::get_direction(const Vector3& x) const {
    return Vector3();
}
