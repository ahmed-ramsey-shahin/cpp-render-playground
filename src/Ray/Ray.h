#ifndef _RAY_H_
#define _RAY_H_

#include "../Vector3/Vector3.h"

class Ray {
private:
    Vector3 o; // origin
    Vector3 d; // direction
public:
    Ray();
    Ray(const Vector3&, const Vector3&);
    const Vector3& get_origin() const;
    const Vector3& get_direction() const;
    void set_origin(const Vector3&);
    void set_direction(const Vector3&);
    Vector3 evaluate(const float&) const;
};

#endif // _RAY_H_
