#ifndef _SCENE_H_
#define _SCENE_H_

#include "../camera/camera.h"
#include "../surface_group/surface_group.h"
#include "../light/light.h"
#include "../rgb/rgb.h"
#include <vector>

struct scene {
public:
    rgb color;
    std::vector<const light*> lights;
    const surface_group* group;
    const camera* cam;
};

#endif // _SCENE_H_
