#ifndef _SURFACE_GROUP_H_
#define _SURFACE_GROUP_H_

#include "../surface/surface.h"
#include "../ray/ray.h"
#include "../hit_record/hit_record.h"
#include <vector>
#include <limits>
#include <algorithm>

class surface_group : public surface {
private:
    std::vector<const surface*> objects;
    int no_objects;
public:
    surface_group();
    int get_no_objects() const;
    void add_object(const surface*);
    void delete_object(const surface*);
    void hit(const ray*, hit_record*&) const;
    void get_normal(hit_record*&) const;
};

#endif // _SURFACE_GROUP_H_
