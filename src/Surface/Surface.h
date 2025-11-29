#ifndef _SURFACE_H_
#define _SURFACE_H_

#include "../Ray/Ray.h"
#include "../RGB/RGB.h"
#include "../Material/Material.h"
#include "../Vector3/Vector3.h"

struct HitRecord;

class Surface {
public:
    Material* mat;
    virtual void hit(const Ray*, HitRecord*&) const = 0;
    virtual void get_normal(HitRecord*&) const = 0;
    virtual ~Surface() = default;
};

#endif // _SURFACE_H_
