#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "../Vector3/Vector3.h"
#include "../Ray/Ray.h"
#include <cmath>

enum camera_type {
    ORTHONORMAL,
    OBLIQUE
};

class Camera {
private:
    Vector3 origin;
    Vector3 target;
    Vector3 u, v, w;
    float focal_length;
    float l, r;
    float t, b;
    camera_type type;
    void calculate_basis();
public:
    Camera(const float&, const float&, const float&, const Vector3&, const Vector3&);
    float get_focal_length() const;
    void set_focal_length(const float&);
    float get_width() const;
    void set_width(const float&);
    float get_height() const;
    void set_height(const float&);
    const camera_type& get_type() const;
    void set_type(const camera_type&);
    const Vector3& get_target() const;
    void set_target(const Vector3&);
    Ray* get_ray(const float&, const float&) const;
    void set_origin(const Vector3&);
    const Vector3& get_origin() const;
};

#endif // _CAMERA_H_
