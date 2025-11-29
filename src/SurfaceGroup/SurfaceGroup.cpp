#include "SurfaceGroup.h"

SurfaceGroup::SurfaceGroup() {
    objects = std::vector<const Surface*>();
}


int SurfaceGroup::get_no_objects() const {
    return no_objects;
}

void SurfaceGroup::add_object(const Surface* object) {
    objects.push_back(object);
    no_objects++;
}

void SurfaceGroup::delete_object(const Surface* object) {
    auto it = std::find(objects.begin(), objects.end(), object);
    if (it != objects.end()) {
        objects.erase(it);
        no_objects--;
    }
}

void SurfaceGroup::hit(const Ray* r, HitRecord*& record) const {
    HitRecord* min_record = new HitRecord();
    min_record->s = nullptr;
    min_record->hit_distance = std::numeric_limits<float>::max();
    for (auto object : objects) {
        object->hit(r, record);
        if (min_record->hit_distance > record->hit_distance) {
            min_record->s = record->s;
            min_record->hit_distance = record->hit_distance;
        }
    }
    delete record;
    record = min_record;
}

void SurfaceGroup::get_normal(HitRecord*& record) const {
    record->s->get_normal(record);
}
