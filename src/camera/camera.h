#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "../vector3/vector3.h"
#include "../ray/ray.h"
#include <cmath>

enum camera_type {
    ORTHONORMAL,
    OBLIQUE
};

class camera {
private:
    vector3 origin;
    vector3 target;
    vector3 u, v, w;
    float focal_length;
    float l, r;
    float t, b;
    camera_type type;
    void calculate_basis();
public:
    camera(const float&, const float&, const float&, const vector3&, const vector3&);
    float get_focal_length() const;
    void set_focal_length(const float&);
    float get_width() const;
    void set_width(const float&);
    float get_height() const;
    void set_height(const float&);
    const camera_type& get_type() const;
    void set_type(const camera_type&);
    const vector3& get_target() const;
    void set_target(const vector3&);
    ray* get_ray(const float&, const float&) const;
    void set_origin(const vector3&);
    const vector3& get_origin() const;
};

#endif // _CAMERA_H_
