#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "../vector3/vector3.h"
#include "../rgb/rgb.h"

class material {
public:
    rgb color;
    virtual rgb evaluate(const vector3&, const vector3&, const vector3&);
    virtual ~material() = default;
};

#endif // _MATERIAL_H_
