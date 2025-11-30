#ifndef _DIRECTIONAL_LIGHT_H_
#define _DIRECTIONAL_LIGHT_H_

#include "../Light/Light.h"
#include "../RGB/RGB.h"
#include "../LightRecord/LightRecord.h"
#include "../Vector3/Vector3.h"

class DirectionalLight : public Light {
private:
    RGB intensity;
    Vector3 direction;
public:
    DirectionalLight();
    DirectionalLight(const Vector3&);
    const RGB& get_intensity() const;
    void set_intensity(const RGB&);
    const Vector3& get_direction() const;
    void set_direction(const Vector3&);
    RGB illuminate(LightRecord&) const;
    Vector3 get_direction(const Vector3&) const;
};

#endif // _DIRECTIONAL_LIGHT_H_
