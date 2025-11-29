#ifndef _SCENE_H_
#define _SCENE_H_

#include "../Camera/Camera.h"
#include "../SurfaceGroup/SurfaceGroup.h"
#include "../Light/Light.h"
#include "../RGB/RGB.h"
#include <vector>

struct Scene {
public:
    RGB color;
    std::vector<const Light*> lights;
    const SurfaceGroup* group;
    const Camera* cam;
};

#endif // _SCENE_H_
