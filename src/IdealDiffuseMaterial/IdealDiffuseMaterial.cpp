#include "IdealDiffuseMaterial.h"

RGB IdealDiffuseMaterial::evaluate(const Vector3& l, const Vector3& n, const Vector3& v) const {
    return color;
}
