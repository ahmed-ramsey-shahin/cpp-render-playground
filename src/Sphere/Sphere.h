#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "../Surface/Surface.h"
#include "../Vector3/Vector3.h"
#include "../Ray/Ray.h"
#include "../HitRecord/HitRecord.h"
#include <cmath>

class Sphere : public Surface {
private:
    Vector3 center;
    float radius;
public:
    Sphere();
    Sphere(const float&, const float&, const float&, const float&);
    Sphere(const Vector3&, const float&);
    void move_to(const float&, const float&, const float&);
    void move_to(const Vector3&);
    const Vector3& get_center() const;
    float get_radius() const;
    void set_radius(const float&);
    bool hit(const Ray*, HitRecord*&) const;
    void get_normal(HitRecord*&) const;
};

#endif // _SPHERE_H_
