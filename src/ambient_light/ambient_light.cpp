#include "ambient_light.h"

void ambient_light::set_color(const rgb& color) {
    this->color = color;
}
const rgb& ambient_light::get_color() const {
    return color;
}


rgb ambient_light::illuminate(const ray* r, const hit_record& record) const {
    rgb color = record.s->mat->color;
    return rgb(
        this->color.get(0)*color[0],
        this->color.get(1)*color[1],
        this->color.get(2)*color[2]
    );
}
