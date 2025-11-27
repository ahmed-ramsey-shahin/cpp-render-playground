#include "ray.h"

ray::ray() {
    o = vector3();
    d = vector3();
}

ray::ray(const vector3& origin, const vector3& direction) {
    o = origin;
    d = direction;
}

vector3 ray::evaluate(const float& t) const {
    vector3 result;
    result = o + (d * t);
    return result;
}

const vector3& ray::get_origin() const {
    return o;
}

const vector3& ray::get_direction() const {
    return d;
}

void ray::set_origin(const vector3& origin) {
    o = origin;
}

void ray::set_direction(const vector3& direction) {
    d = direction;
}
