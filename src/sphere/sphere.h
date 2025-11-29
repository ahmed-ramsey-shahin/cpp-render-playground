#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "../surface/surface.h"
#include "../vector3/vector3.h"
#include "../ray/ray.h"
#include "../hit_record/hit_record.h"
#include <cmath>

class sphere : public surface {
private:
    vector3 center;
    float radius;
public:
    sphere();
    sphere(const float&, const float&, const float&, const float&);
    sphere(const vector3&, const float&);
    void move_to(const float&, const float&, const float&);
    void move_to(const vector3&);
    const vector3& get_center() const;
    float get_radius() const;
    void set_radius(const float&);
    void hit(const ray*, hit_record*&) const;
    void get_normal(hit_record*&) const;
};

#endif // _SPHERE_H_
