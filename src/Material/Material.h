#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "../Vector3/Vector3.h"
#include "../RGB/RGB.h"

class Material {
public:
    RGB color;
    virtual RGB evaluate(const Vector3&, const Vector3&, const Vector3&);
    virtual ~Material() = default;
};

#endif // _MATERIAL_H_
