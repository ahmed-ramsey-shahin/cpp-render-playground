#ifndef _VECTOR2_H_
#define _VECTOR2_H_

#include <cmath>

class Vector2 {
private:
    float xy[2];
public:
    Vector2(const float, const float);
    Vector2();
    float& operator[](const short&);
    Vector2 operator+(const Vector2&) const;
    Vector2 operator-(const Vector2&) const;
    Vector2 operator*(const float&) const;
    Vector2 operator/(const float&) const;
    Vector2 operator-() const;
    Vector2 operator+() const;
    float dot(const Vector2&) const;
    float cross(const Vector2&) const;
    float magnitude() const;
};

#endif // _VECTOR2_H_
