#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "../Surface/Surface.h"
#include "../Vector3/Vector3.h"
#include "../Ray/Ray.h"
#include "../HitRecord/HitRecord.h"
#include <cmath>

class Triangle : public Surface {
private:
    Vector3 a;
    Vector3 b;
    Vector3 c;
public:
    Triangle();
    Triangle(const Vector3&, const Vector3&, const Vector3&);
    void move_to(const Vector3&, const Vector3&, const Vector3&);
    void set_a(const Vector3&);
    void set_b(const Vector3&);
    void set_c(const Vector3&);
    const Vector3& get_a() const;
    const Vector3& get_b() const;
    const Vector3& get_c() const;
    bool hit(const Ray*, HitRecord*&) const;
    void get_normal(HitRecord*&) const;
};

#endif // _TRIANGLE_H_
