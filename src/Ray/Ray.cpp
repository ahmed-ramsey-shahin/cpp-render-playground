#include "Ray.h"

Ray::Ray() {
    o = Vector3();
    d = Vector3();
}

Ray::Ray(const Vector3& origin, const Vector3& direction) {
    o = origin;
    d = direction;
}

Vector3 Ray::evaluate(const float& t) const {
    Vector3 result;
    result = o + (d * t);
    return result;
}

const Vector3& Ray::get_origin() const {
    return o;
}

const Vector3& Ray::get_direction() const {
    return d;
}

void Ray::set_origin(const Vector3& origin) {
    o = origin;
}

void Ray::set_direction(const Vector3& direction) {
    d = direction;
}
