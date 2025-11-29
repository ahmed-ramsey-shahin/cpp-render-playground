#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "../LightRecord/LightRecord.h"
#include "../RGB/RGB.h"
#include "../Ray/Ray.h"
#include "../Vector3/Vector3.h"

class Light {
public:
    virtual RGB illuminate(LightRecord&) const = 0;
    virtual Vector3 get_direction(const Vector3&) const = 0;
    virtual ~Light() = default;
};

#endif // _LIGHT_H_
