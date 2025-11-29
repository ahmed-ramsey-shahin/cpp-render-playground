#ifndef _POINT_LIGHT_H_
#define _POINT_LIGHT_H_

#include "../Light/Light.h"
#include "../RGB/RGB.h"
#include "../Vector3/Vector3.h"
#include "../Surface/Surface.h"
#include <cmath>

class PointLight : public Light {
private:
    RGB intensity;
    Vector3 p;
public:
    RGB illuminate(const Ray*, const HitRecord&) const;
    void set_position(const Vector3&);
    const Vector3& get_position() const;
    void set_intensity(const RGB&);
    const RGB& get_intensity() const;
};

#endif // _POINT_LIGHT_H_
