#ifndef _POINT_LIGHT_H_
#define _POINT_LIGHT_H_

#include "../light/light.h"
#include "../rgb/rgb.h"
#include "../vector3/vector3.h"
#include "../surface/surface.h"
#include <cmath>

class point_light : public light {
private:
    rgb color;
    vector3 p;
public:
    rgb illuminate(const ray*, const hit_record&) const;
    void set_position(const vector3&);
    const vector3& get_position() const;
    void set_color(const rgb&);
    const rgb& get_color() const;
};

#endif // _POINT_LIGHT_H_
