#include "surface_group.h"

surface_group::surface_group() {
    objects = std::vector<const surface*>();
}


int surface_group::get_no_objects() const {
    return no_objects;
}

void surface_group::add_object(const surface* object) {
    objects.push_back(object);
    no_objects++;
}

void surface_group::delete_object(const surface* object) {
    auto it = std::find(objects.begin(), objects.end(), object);
    if (it != objects.end()) {
        objects.erase(it);
        no_objects--;
    }
}

void surface_group::hit(const ray* r, hit_record*& record) const {
    hit_record* min_record = new hit_record();
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

void surface_group::get_normal(hit_record*& record) const {
    record->s->get_normal(record);
}
