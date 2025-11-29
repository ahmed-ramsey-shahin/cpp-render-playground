#include "AmbientLight.h"

void AmbientLight::set_intensity(const RGB& intensity) {
    this->intensity = intensity;
}
const RGB& AmbientLight::get_intensity() const {
    return intensity;
}


RGB AmbientLight::illuminate(const Ray* r, const HitRecord& record) const {
    RGB intensity = record.s->mat->color;
    return RGB(
        this->intensity.get(0)*intensity[0],
        this->intensity.get(1)*intensity[1],
        this->intensity.get(2)*intensity[2]
    );
}
