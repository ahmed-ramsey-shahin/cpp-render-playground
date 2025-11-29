#include "SpecularMaterial.h"

SpecularMaterial::SpecularMaterial() {
    specular_coefficient = RGB();
    phong_exponent = 10;
}

SpecularMaterial::SpecularMaterial(const RGB& specular_coefficient, int phong_exponent) {
    this->phong_exponent = phong_exponent;
    this->specular_coefficient = specular_coefficient;
}

RGB SpecularMaterial::evaluate(const Vector3& l, const Vector3& n, const Vector3& v) const {
    Vector3 h = (l + v) / (l + v).magnitude();
    return color / M_PI + specular_coefficient * std::pow(std::max(0.0f, n.dot(h)), phong_exponent);
}

int SpecularMaterial::get_phong_exponent() const {
    return phong_exponent;
}

void SpecularMaterial::set_phong_exponent(int phong_exponent) {
    this->phong_exponent = phong_exponent;
}

const RGB& SpecularMaterial::get_specular_coefficient() const {
    return specular_coefficient;
}

void SpecularMaterial::set_specular_coefficient(const RGB& specular_coefficient) {
    this->specular_coefficient = specular_coefficient;
}
