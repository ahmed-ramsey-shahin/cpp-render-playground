#ifndef _HIT_RECORD_H_
#define _HIT_RECORD_H_

#include "../Vector3/Vector3.h"

class Surface;

struct HitRecord {
    const Surface* s;
    float hit_distance;
    Vector3 hit_point;
    Vector3 n;
};

#endif // _HIT_RECORD_H_
