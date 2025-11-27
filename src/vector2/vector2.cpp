#include "vector2.h"

vector2::vector2(const float x, const float y) {
    xy[0] = x;
    xy[1] = y;
}

vector2::vector2() {
    xy[0] = 0;
    xy[1] = 0;
}

float& vector2::operator[](const short& i) {
    return xy[i];
}

vector2 vector2::operator+(const vector2& other) const {
    vector2 result;
    result[0] = xy[0] + other.xy[0];
    result[1] = xy[1] + other.xy[1];
    return result;
}

vector2 vector2::operator-(const vector2& other) const {
    vector2 result;
    result[0] = xy[0] - other.xy[0];
    result[1] = xy[1] - other.xy[1];
    return result;
}

vector2 vector2::operator*(const float& x) const {
    vector2 result;
    result[0] = xy[0] * x;
    result[1] = xy[1] * x;
    return result;
}

vector2 vector2::operator/(const float& x) const {
    vector2 result;
    result[0] = xy[0] / x;
    result[1] = xy[1] / x;
    return result;
}

vector2 vector2::operator-() const {
    vector2 result;
    result[0] = -xy[0];
    result[1] = -xy[1];
    return result;
}

vector2 vector2::operator+() const {
    vector2 result;
    result[0] = +xy[0];
    result[1] = +xy[1];
    return result;
}

float vector2::dot(const vector2& other) const {
    float result;
    result = xy[0] * other.xy[0] + xy[1] * other.xy[1];
    return result;
}

float vector2::cross(const vector2& other) const {
    float result;
    result = xy[0] * other.xy[1] - xy[1] * other.xy[0];
    return result;
}

float vector2::magnitude() const {
    return std::sqrt(std::pow(xy[0], 2) + std::pow(xy[1], 2));
}
