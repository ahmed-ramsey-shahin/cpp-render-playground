#include "AmbientLight.h"

void AmbientLight::set_intensity(const RGB& intensity) {
    this->intensity = intensity;
}
const RGB& AmbientLight::get_intensity() const {
    return intensity;
}


RGB AmbientLight::illuminate(const HitRecord& record) const {
    return intensity;
}
