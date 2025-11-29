#ifndef _SURFACE_GROUP_H_
#define _SURFACE_GROUP_H_

#include "../Surface/Surface.h"
#include "../Ray/Ray.h"
#include "../HitRecord/HitRecord.h"
#include <vector>
#include <limits>
#include <algorithm>

class SurfaceGroup : public Surface {
private:
    std::vector<const Surface*> objects;
    int no_objects;
public:
    SurfaceGroup();
    int get_no_objects() const;
    void add_object(const Surface*);
    void delete_object(const Surface*);
    void hit(const Ray*, HitRecord*&) const;
    void get_normal(HitRecord*&) const;
};

#endif // _SURFACE_GROUP_H_
