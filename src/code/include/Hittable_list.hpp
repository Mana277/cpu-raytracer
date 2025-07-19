#pragma once 

// Header contents (class and function declarations)
#include "Hittable.hpp"
#include "Interval.hpp"
#include <memory>
#include <vector>

using std::make_shared;
using std::shared_ptr;

class Hittable_list : public Hittable {
  public:
    std::vector<shared_ptr<Hittable>> objects;

    //Constructor
    Hittable_list() {}
    Hittable_list(shared_ptr<Hittable> object) { add(object); }

    //member function
    void clear() { objects.clear(); }

    void add(shared_ptr<Hittable> object) {
        objects.push_back(object);
    }

    bool hitRay(const Ray& r, const Interval& ivl, Hit_record& rec) const override {
        Hit_record temp_rec;
        bool hit_anything = false;
        double closest_so_far = ivl.max;

        for (const auto& object : objects) {
            if (object->hitRay(r, Interval(ivl.min, closest_so_far), temp_rec)) {
                hit_anything = true;
                closest_so_far = temp_rec.T;
                rec = temp_rec;
            }
        }

        return hit_anything;
    }
};