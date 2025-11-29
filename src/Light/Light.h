#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "../HitRecord/HitRecord.h"
#include "../RGB/RGB.h"
#include "../Ray/Ray.h"

class Light {
public:
    virtual RGB illuminate(const Ray*, const HitRecord&) const = 0;
    virtual ~Light() = default;
};

#endif // _LIGHT_H_
