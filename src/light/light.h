#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "../hit_record/hit_record.h"
#include "../rgb/rgb.h"
#include "../ray/ray.h"

class light {
public:
    virtual rgb illuminate(const ray*, const hit_record&) const = 0;
    virtual ~light() = default;
};

#endif // _LIGHT_H_
