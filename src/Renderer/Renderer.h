#ifndef _RNDERER_H_
#define _RNDERER_H_

#include "../Scene/Scene.h"
#include "../Light/Light.h"
#include "../HitRecord/HitRecord.h"
#include "../Camera/Camera.h"
#include "../Image/Image.h"
#include "../Ray/Ray.h"
#include "../RGB/RGB.h"

class Renderer {
private:
    RGB trace_ray(const Ray*, const Scene&) const;
public:
    void render(const Scene&, const Camera&, Image&) const;
};

#endif // _RNDERER_H_
