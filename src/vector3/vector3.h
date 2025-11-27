#ifndef _VECTOR3_H_
#define _VECTOR3_H_

#include <cmath>

class vector3 {
private:
    float xyz[3];
public:
    vector3(const float, const float, const float);
    vector3();
    float& operator[](const short&);
    vector3 operator+(const vector3&) const;
    vector3 operator-(const vector3&) const;
    vector3 operator*(const float&) const;
    vector3 operator/(const float&) const;
    vector3 operator-() const;
    vector3 operator+() const;
    vector3 cross(const vector3&) const;
    const float& get(const short&) const;
    float dot(const vector3&) const;
    float magnitude() const;
};

#endif // _VECTOR3_H_
