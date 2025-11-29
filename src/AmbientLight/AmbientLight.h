#ifndef _AMBIENT_LIGHT_H_
#define _AMBIENT_LIGHT_H_

#include "../Light/Light.h"
#include "../RGB/RGB.h"
#include "../Surface/Surface.h"
#include "../Ray/Ray.h"

class AmbientLight : public Light {
private:
    RGB intensity;
public:
    RGB illuminate(const Ray*, const HitRecord&) const;
    void set_intensity(const RGB&);
    const RGB& get_intensity() const;
};

#endif // _AMBIENT_LIGHT_H_
