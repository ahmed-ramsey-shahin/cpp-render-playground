#ifndef _SPECULAR_MATERIAL_H_
#define _SPECULAR_MATERIAL_H_
#define _USE_MATH_DEFINES

#include "../RGB/RGB.h"
#include "../Material/Material.h"
#include "../Vector3/Vector3.h"
#include <cmath>

class SpecularMaterial : public Material {
private:
    int phong_exponent;
    RGB specular_coefficient;
public:
    SpecularMaterial();
    SpecularMaterial(const RGB&, int);
    int get_phong_exponent() const;
    void set_phong_exponent(int);
    const RGB& get_specular_coefficient() const;
    void set_specular_coefficient(const RGB&);
    RGB evaluate(const Vector3&, const Vector3&, const Vector3&) const;
};

#endif // _SPECULAR_MATERIAL_H_
