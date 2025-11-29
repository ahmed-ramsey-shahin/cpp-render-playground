#ifndef _IDEAL_DIFFUSE_MATERIAL_H_
#define _IDEAL_DIFFUSE_MATERIAL_H_
#define _USE_MATH_DEFINES

#include "../RGB/RGB.h"
#include "../Material/Material.h"
#include "../Vector3/Vector3.h"
#include <cmath>

class IdealDiffuseMaterial : public Material {
public:
    RGB evaluate(const Vector3&, const Vector3&, const Vector3&) const;
};

#endif // _IDEAL_DIFFUSE_MATERIAL_H_
