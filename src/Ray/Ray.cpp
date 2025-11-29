#include "Ray.h"

Ray::Ray() {
    origin = Vector3();
    direction = Vector3();
}

Ray::Ray(const Vector3& origin, const Vector3& direction) {
    this->origin = origin;
    this->direction = direction;
}

Vector3 Ray::evaluate(const float& t) const {
    Vector3 result;
    result = origin + (direction * t);
    return result;
}

const Vector3& Ray::get_origin() const {
    return origin;
}

const Vector3& Ray::get_direction() const {
    return direction;
}

void Ray::set_origin(const Vector3& origin) {
    this->origin = origin;
}

void Ray::set_direction(const Vector3& direction) {
    this->direction = direction;
}
