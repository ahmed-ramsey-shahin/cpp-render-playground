#include "Vector2.h"

Vector2::Vector2(const float x, const float y) {
    xy[0] = x;
    xy[1] = y;
}

Vector2::Vector2() {
    xy[0] = 0;
    xy[1] = 0;
}

float& Vector2::operator[](const short& i) {
    return xy[i];
}

Vector2 Vector2::operator+(const Vector2& other) const {
    Vector2 result;
    result[0] = xy[0] + other.xy[0];
    result[1] = xy[1] + other.xy[1];
    return result;
}

Vector2 Vector2::operator-(const Vector2& other) const {
    Vector2 result;
    result[0] = xy[0] - other.xy[0];
    result[1] = xy[1] - other.xy[1];
    return result;
}

Vector2 Vector2::operator*(const float& x) const {
    Vector2 result;
    result[0] = xy[0] * x;
    result[1] = xy[1] * x;
    return result;
}

Vector2 Vector2::operator/(const float& x) const {
    Vector2 result;
    result[0] = xy[0] / x;
    result[1] = xy[1] / x;
    return result;
}

Vector2 Vector2::operator-() const {
    Vector2 result;
    result[0] = -xy[0];
    result[1] = -xy[1];
    return result;
}

Vector2 Vector2::operator+() const {
    Vector2 result;
    result[0] = +xy[0];
    result[1] = +xy[1];
    return result;
}

float Vector2::dot(const Vector2& other) const {
    float result;
    result = xy[0] * other.xy[0] + xy[1] * other.xy[1];
    return result;
}

float Vector2::cross(const Vector2& other) const {
    float result;
    result = xy[0] * other.xy[1] - xy[1] * other.xy[0];
    return result;
}

float Vector2::magnitude() const {
    return std::sqrt(std::pow(xy[0], 2) + std::pow(xy[1], 2));
}
