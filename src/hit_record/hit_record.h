#ifndef _HIT_RECORD_H_
#define _HIT_RECORD_H_

#include "../vector3/vector3.h"

class surface;

struct hit_record {
    const surface* s;
    float hit_distance;
    vector3 hit_point;
    vector3 n;
};

#endif // _HIT_RECORD_H_
