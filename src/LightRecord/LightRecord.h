#ifndef _LIGHT_RECORD_H_
#define _LIGHT_RECORD_H_

#include "../Vector3/Vector3.h"

struct LightRecord {
    Vector3 surface_normal;
    Vector3 hit_point;
    Vector3 view_direction;
    Vector3 light_direction;
    float light_distance;
};

#endif // _LIGHT_RECORD_H_
