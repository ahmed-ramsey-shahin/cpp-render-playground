#ifndef _VECTOR3_H_
#define _VECTOR3_H_

#include <cmath>

class Vector3 {
private:
    float xyz[3];
public:
    Vector3(const float, const float, const float);
    Vector3();
    float& operator[](const short&);
    Vector3 operator+(const Vector3&) const;
    Vector3 operator-(const Vector3&) const;
    Vector3 operator*(const float&) const;
    Vector3 operator/(const float&) const;
    Vector3 operator-() const;
    Vector3 operator+() const;
    Vector3 cross(const Vector3&) const;
    const float& get(const short&) const;
    float dot(const Vector3&) const;
    float magnitude() const;
};

#endif // _VECTOR3_H_
