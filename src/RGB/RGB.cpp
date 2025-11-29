#include "RGB.h"

RGB::RGB(const float x, const float y, const float z) {
    xyz[0] = x;
    xyz[1] = y;
    xyz[2] = z;
}

RGB::RGB() {
    xyz[0] = 0;
    xyz[1] = 0;
    xyz[2] = 0;
}

float& RGB::operator[](const short& i) {
    return xyz[i];
}

RGB RGB::operator+(const RGB& other) const {
    RGB result;
    result[0] = xyz[0] + other.xyz[0];
    result[1] = xyz[1] + other.xyz[1];
    result[2] = xyz[2] + other.xyz[2];
    return result;
}

RGB RGB::operator-(const RGB& other) const {
    RGB result;
    result[0] = xyz[0] - other.xyz[0];
    result[1] = xyz[1] - other.xyz[1];
    result[2] = xyz[2] - other.xyz[2];
    return result;
}

RGB RGB::operator*(const float& x) const {
    RGB result;
    result[0] = xyz[0] * x;
    result[1] = xyz[1] * x;
    result[2] = xyz[2] * x;
    return result;
}

RGB RGB::operator/(const float& x) const {
    RGB result;
    result[0] = xyz[0] / x;
    result[1] = xyz[1] / x;
    result[2] = xyz[2] / x;
    return result;
}

const float& RGB::get(const short& i) const {
    return xyz[i];
}
