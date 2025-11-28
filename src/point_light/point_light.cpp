#include "point_light.h"

rgb point_light::illuminate(const ray& r, const hit_record& record) const {
    vector3 x = r.evaluate(record.hit_point);
    float rr = (p - x).magnitude();
    vector3 l = (p - x) / rr;
    vector3 n = record.n;
    rgb e = (color / std::pow(rr, 2)) * std::max(0.0f, n.dot(l));
    rgb k = record.s->mat->evaluate(l, r.get_direction() / r.get_direction().magnitude(), n);
    return rgb(e[0]*k[0], e[1]*k[1], e[2]*k[2]);
}

void point_light::set_position(const vector3& p) {
    this->p = p;
}
const vector3& point_light::get_position() const {
    return p;
}

void point_light::set_color(const rgb& color) {
    this->color = color;
}
const rgb& point_light::get_color() const {
    return this->color;
}
