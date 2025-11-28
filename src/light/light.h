#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "../hit_record/hit_record.h"
#include "../rgb/rgb.h"
#include "../ray/ray.h"

class light {
public:
    rgb illuminate(const ray&, const hit_record&) const;
};

#endif // _LIGHT_H_
