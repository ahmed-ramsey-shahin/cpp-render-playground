#ifndef _AMBIENT_LIGHT_H_
#define _AMBIENT_LIGHT_H_

#include "../light/light.h"
#include "../rgb/rgb.h"
#include "../surface/surface.h"

class ambient_light : public light {
private:
    rgb color;
public:
    rgb illuminate(const ray*, const hit_record&) const;
    void set_color(const rgb&);
    const rgb& get_color() const;
};

#endif // _AMBIENT_LIGHT_H_
