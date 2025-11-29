#ifndef _SURFACE_H_
#define _SURFACE_H_

#include "../ray/ray.h"
#include "../rgb/rgb.h"
#include "../material/material.h"
#include "../vector3/vector3.h"

struct hit_record;

class surface {
public:
    material* mat;
    virtual void hit(const ray*, hit_record*&) const = 0;
    virtual void get_normal(hit_record*&) const = 0;
    virtual ~surface() = default;
};

#endif // _SURFACE_H_
