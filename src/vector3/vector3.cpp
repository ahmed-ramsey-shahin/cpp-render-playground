#include "vector3.h"

vector3::vector3(const float x, const float y, const float z) {
    xyz[0] = x;
    xyz[1] = y;
    xyz[2] = z;
}

vector3::vector3() {
    xyz[0] = 0;
    xyz[1] = 0;
    xyz[2] = 0;
}

float& vector3::operator[](const short& i) {
    return xyz[i];
}

vector3 vector3::operator+(const vector3& other) const {
    vector3 result;
    result[0] = xyz[0] + other.xyz[0];
    result[1] = xyz[1] + other.xyz[1];
    result[2] = xyz[2] + other.xyz[2];
    return result;
}

vector3 vector3::operator-(const vector3& other) const {
    vector3 result;
    result[0] = xyz[0] - other.xyz[0];
    result[1] = xyz[1] - other.xyz[1];
    result[2] = xyz[2] - other.xyz[2];
    return result;
}

vector3 vector3::operator*(const float& x) const {
    vector3 result;
    result[0] = xyz[0] * x;
    result[1] = xyz[1] * x;
    result[2] = xyz[2] * x;
    return result;
}

vector3 vector3::operator/(const float& x) const {
    vector3 result;
    result[0] = xyz[0] / x;
    result[1] = xyz[1] / x;
    result[2] = xyz[2] / x;
    return result;
}

vector3 vector3::operator-() const {
    vector3 result;
    result[0] = -xyz[0];
    result[1] = -xyz[1];
    result[2] = -xyz[2];
    return result;
}

vector3 vector3::operator+() const {
    vector3 result;
    result[0] = +xyz[0];
    result[1] = +xyz[1];
    result[2] = +xyz[2];
    return result;
}

float vector3::dot(const vector3& other) const {
    float result;
    result = xyz[0] * other.xyz[0] + xyz[1] * other.xyz[1] + xyz[2] * other.xyz[2];
    return result;
}

vector3 vector3::cross(const vector3& other) const {
    vector3 result;
    result[0] = xyz[1] * other.xyz[2] - xyz[2] * other.xyz[1];
    result[1] = xyz[2] * other.xyz[0] - xyz[0] * other.xyz[2];
    result[2] = xyz[0] * other.xyz[1] - xyz[1] * other.xyz[0];
    return result;
}

float vector3::magnitude() const {
    return std::sqrt(std::pow(xyz[0], 2) + std::pow(xyz[1], 2) + std::pow(xyz[2], 2));
}

const float& vector3::get(const short& i) const {
    return xyz[i];
}
