#include "rgb.h"

rgb::rgb(const float x, const float y, const float z) {
    xyz[0] = x;
    xyz[1] = y;
    xyz[2] = z;
}

rgb::rgb() {
    xyz[0] = 0;
    xyz[1] = 0;
    xyz[2] = 0;
}

float& rgb::operator[](const short& i) {
    return xyz[i];
}

rgb rgb::operator+(const rgb& other) const {
    rgb result;
    result[0] = xyz[0] + other.xyz[0];
    result[1] = xyz[1] + other.xyz[1];
    result[2] = xyz[2] + other.xyz[2];
    return result;
}

rgb rgb::operator-(const rgb& other) const {
    rgb result;
    result[0] = xyz[0] - other.xyz[0];
    result[1] = xyz[1] - other.xyz[1];
    result[2] = xyz[2] - other.xyz[2];
    return result;
}

rgb rgb::operator*(const float& x) const {
    rgb result;
    result[0] = xyz[0] * x;
    result[1] = xyz[1] * x;
    result[2] = xyz[2] * x;
    return result;
}

rgb rgb::operator/(const float& x) const {
    rgb result;
    result[0] = xyz[0] / x;
    result[1] = xyz[1] / x;
    result[2] = xyz[2] / x;
    return result;
}

const float& rgb::get(const short& i) const {
    return xyz[i];
}
