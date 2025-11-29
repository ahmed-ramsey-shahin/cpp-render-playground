#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "../surface/surface.h"
#include "../vector3/vector3.h"
#include "../ray/ray.h"
#include "../hit_record/hit_record.h"
#include <cmath>

class triangle : public surface {
private:
    vector3 a;
    vector3 b;
    vector3 c;
public:
    triangle();
    triangle(const vector3&, const vector3&, const vector3&);
    void move_to(const vector3&, const vector3&, const vector3&);
    void set_a(const vector3&);
    void set_b(const vector3&);
    void set_c(const vector3&);
    const vector3& get_a() const;
    const vector3& get_b() const;
    const vector3& get_c() const;
    void hit(const ray*, hit_record*&) const;
};

#endif // _TRIANGLE_H_
