#ifndef _VECTOR2_H_
#define _VECTOR2_H_

#include <cmath>

class vector2 {
private:
    float xy[2];
public:
    vector2(const float, const float);
    vector2();
    float& operator[](const short&);
    vector2 operator+(const vector2&) const;
    vector2 operator-(const vector2&) const;
    vector2 operator*(const float&) const;
    vector2 operator/(const float&) const;
    vector2 operator-() const;
    vector2 operator+() const;
    float dot(const vector2&) const;
    float cross(const vector2&) const;
    float magnitude() const;
};

#endif // _VECTOR2_H_
