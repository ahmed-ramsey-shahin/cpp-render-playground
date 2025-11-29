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

bool SurfaceGroup::hit(const Ray* r, HitRecord*& record) const {
    HitRecord* min_record = new HitRecord();
    HitRecord* temp_record = new HitRecord();
    min_record->s = nullptr;
    min_record->hit_distance = std::numeric_limits<float>::max();
    temp_record->hit_distance = std::numeric_limits<float>::max();

    for (auto object : objects) {
        object->hit(r, temp_record);
        if (min_record->hit_distance > temp_record->hit_distance) {
            min_record->s = temp_record->s;
            min_record->hit_distance = temp_record->hit_distance;
        }
    }

    float hit_distance = min_record->hit_distance;

    if (record != nullptr) {
        delete record;
        record = min_record;
    } else {
        delete min_record;
    }

    delete temp_record;
    return hit_distance < std::numeric_limits<float>::max();
}

void SurfaceGroup::get_normal(HitRecord*& record) const {
    record->s->get_normal(record);
}
