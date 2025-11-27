#ifndef _RAY_H_
#define _RAY_H_

#include "../vector3/vector3.h"

class ray {
private:
    vector3 o; // origin
    vector3 d; // direction
public:
    ray();
    ray(const vector3&, const vector3&);
    const vector3& get_origin() const;
    const vector3& get_direction() const;
    void set_origin(const vector3&);
    void set_direction(const vector3&);
    vector3 evaluate(const float&) const;
};

#endif // _RAY_H_
