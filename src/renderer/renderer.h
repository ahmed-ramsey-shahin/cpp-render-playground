#ifndef _RNDERER_H_
#define _RNDERER_H_

#include "../surface_group/surface_group.h"
#include "../hit_record/hit_record.h"
#include "../camera/camera.h"
#include "../image/image.h"
#include "../ray/ray.h"
#include "../rgb/rgb.h"

class renderer {
private:
    rgb trace_ray(const ray*, const surface_group&) const;
public:
    void render(const surface_group&, const camera&, image&) const;
};

#endif // _RNDERER_H_
