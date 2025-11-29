#include "triangle.h"

triangle::triangle() {
    a = vector3();
    b = vector3();
    c = vector3();
}

triangle::triangle(const vector3& a, const vector3& b, const vector3& c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

void triangle::move_to(const vector3& a, const vector3& b, const vector3& c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

void triangle::set_a(const vector3& a) {
    this->a = a;
}

void triangle::set_b(const vector3& b) {
    this->b = b;
}

void triangle::set_c(const vector3& c) {
    this->c = c;
}

const vector3& triangle::get_a() const {
    return a;
}

const vector3& triangle::get_b() const {
    return b;
}

const vector3& triangle::get_c() const {
    return c;
}

void triangle::hit(const ray* r, hit_record*& record) const {
    record->s = this;
    const vector3 direction = r->get_direction();
    const vector3 eye = r->get_origin();
    float a = this->a.get(0) - this->b.get(0);
    float b = this->a.get(1) - this->b.get(1);
    float c = this->a.get(2) - this->b.get(2);
    float d = this->a.get(0) - this->c.get(0);
    float e = this->a.get(1) - this->c.get(1);
    float f = this->a.get(2) - this->c.get(2);
    float g = direction.get(0);
    float h = direction.get(1);
    float i = direction.get(2);
    float j = this->a.get(0) - eye.get(0);
    float k = this->a.get(1) - eye.get(1);
    float l = this->a.get(2) - eye.get(2);
    float m = a*(e*i - h*f) + b*(g*f - d*i) + c*(d*h - e*g);

    // compute t
    float t = f*(a*k - j*b) + e*(j*c - a*l) + d*(b*l - k*c);
    t = -t/m;
    if (t < 0 || t >= std::numeric_limits<float>::max() || std::isnan(t)) {
        record->hit_distance = std::numeric_limits<float>::max();
        return;
    }

    // compute gamma
    float gamma = i*(a*k - j*b) + h*(j*c - a*l) + g*(b*l - k*c);
    gamma = gamma/m;
    if (gamma < 0 || gamma > 1) {
        record->hit_distance = std::numeric_limits<float>::max();
        return;
    }

    // compute beta
    float beta = j*(e*i - h*f) + k*(g*f - d*i) + l*(d*h - e*g);
    beta = beta / m;
    if (beta < 0 || beta > 1 - gamma) {
        record->hit_distance = std::numeric_limits<float>::max();
        return;
    }

    record->hit_distance = t;
    record->hit_point = r->evaluate(t);
}

void triangle::get_normal(hit_record*& record) const {
    record->n = (b - a).cross(c - a);
}
