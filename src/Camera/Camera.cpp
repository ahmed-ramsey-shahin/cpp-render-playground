#include "Camera.h"

void Camera::calculate_basis() {
    Vector3 vup = Vector3(0, 1, 0);
    w = origin - target;
    w = w / w.magnitude();
    u = vup.cross(w);
    u = u / u.magnitude();
    v = w.cross(u);
}

Camera::Camera(const float& d, const float& w, const float& h, const Vector3& origin, const Vector3& target) {
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

float Camera::get_focal_length() const {
    return focal_length;
}

void Camera::set_focal_length(const float& d) {
    focal_length = d;
    calculate_basis();
}

float Camera::get_width() const {
    return std::abs(r) + std::abs(l);
}

float Camera::get_height() const {
    return std::abs(b) + std::abs(t);
}

void Camera::set_width(const float& w) {
    l = -w / 2;
    r = w / 2;
    calculate_basis();
}

void Camera::set_height(const float& h) {
    t = h / 2;
    b = -h / 2;
    calculate_basis();
}

const camera_type& Camera::get_type() const {
    return type;
}

void Camera::set_type(const camera_type& type) {
    this->type = type;
}

const Vector3& Camera::get_target() const {
    return target;
}

void Camera::set_target(const Vector3& target) {
    this->target = target;
    calculate_basis();
}

Ray* Camera::get_ray(const float& u, const float& v) const {
    Ray* r = new Ray();
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

void Camera::set_origin(const Vector3& origin) {
    this->origin = origin;
    calculate_basis();
}

const Vector3& Camera::get_origin() const {
    return origin;
}
