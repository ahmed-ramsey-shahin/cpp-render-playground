#ifndef _SURFACE_H_
#define _SURFACE_H_

#include "../ray/ray.h"
#include "../rgb/rgb.h"
#include <limits>
#include <cmath>

class hit_record;

class surface {
public:
    rgb color;
    virtual void hit(const ray*, hit_record*&) const = 0;
    virtual ~surface() = default;
};

#endif // _SURFACE_H_
