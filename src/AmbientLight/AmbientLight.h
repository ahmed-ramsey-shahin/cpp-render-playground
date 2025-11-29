#ifndef _AMBIENT_LIGHT_H_
#define _AMBIENT_LIGHT_H_

#include "../Light/Light.h"
#include "../RGB/RGB.h"
#include "../Surface/Surface.h"
#include "../Ray/Ray.h"
#include "../Vector3/Vector3.h"
#include "../LightRecord/LightRecord.h"

class AmbientLight : public Light {
private:
    RGB intensity;
public:
    RGB illuminate(LightRecord&) const;
    void set_intensity(const RGB&);
    const RGB& get_intensity() const;
    Vector3 get_direction(const Vector3&) const;
};

#endif // _AMBIENT_LIGHT_H_
