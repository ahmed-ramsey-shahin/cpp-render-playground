#ifndef _DIRECTIONAL_LIGHT_H_
#define _DIRECTIONAL_LIGHT_H_

#include "../Light/Light.h"
#include "../RGB/RGB.h"
#include "../Vector3/Vector3.h"

class DirectionalLight : public Light {
private:
    RGB intensity;
    Vector3 direction;
public:
    const RGB& get_intensity() const;
    void set_intensity(const RGB&);
    const Vector3& get_direction() const;
    void set_direction(const Vector3&);
    RGB illuminate(const HitRecord&) const;
};

#endif // _DIRECTIONAL_LIGHT_H_
