#include "camera.h"

void camera::calculate_basis() {
    vector3 vup = vector3(0, 1, 0);
    w = origin - target;
    w = w / w.magnitude();
    u = vup.cross(w);
    u = u / u.magnitude();
    v = w.cross(u);
}

camera::camera(const float& d, const float& w, const float& h, const vector3& origin, const vector3& target) {
    focal_length = d;
    l = -w / 2;
    r = w / 2;
    t = h / 2;
    b = -h / 2;
    this->origin = origin;
    this->target = target;
    type = OBLIQUE;
    calculate_basis();
}

float camera::get_focal_length() const {
    return focal_length;
}

void camera::set_focal_length(const float& d) {
    focal_length = d;
    calculate_basis();
}

float camera::get_width() const {
    return std::abs(r) + std::abs(l);
}

float camera::get_height() const {
    return std::abs(b) + std::abs(t);
}

void camera::set_width(const float& w) {
    l = -w / 2;
    r = w / 2;
    calculate_basis();
}

void camera::set_height(const float& h) {
    t = h / 2;
    b = -h / 2;
    calculate_basis();
}

const camera_type& camera::get_type() const {
    return type;
}

void camera::set_type(const camera_type& type) {
    this->type = type;
}

const vector3& camera::get_target() const {
    return target;
}

void camera::set_target(const vector3& target) {
    this->target = target;
    calculate_basis();
}

ray* camera::get_ray(const float& u, const float& v) const {
    ray* r = new ray();
    switch(type) {
        case ORTHONORMAL:
            r->set_origin(origin + this->u * u + this->v * v); 
            r->set_direction(-w);
            break;
        case OBLIQUE:
            r->set_origin(origin);
            r->set_direction(-w * focal_length + this->u * u + this->v * v);
            break;
    }
    return r;
}

void camera::set_origin(const vector3& origin) {
    this->origin = origin;
    calculate_basis();
}

const vector3& camera::get_origin() const {
    return origin;
}
