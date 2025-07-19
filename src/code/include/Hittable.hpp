#pragma once 

// Header contents (class and function declarations)
#include "Ray.hpp"
#include "Vec3.hpp"
#include "Interval.hpp"

class Hit_record {
  public:
    //member variable
    Point3 P;
    Vec3 N;
    double T;
    bool front_face;

    // member function
    void set_face_normal(const Ray& r, const Vec3& outward_normal) {
        front_face = dot(r.getDir(), outward_normal) < 0;
        N = front_face ? outward_normal : (-1)*outward_normal;
    }
};

class Hittable {
  public:
    virtual ~Hittable() = default;

    virtual bool hitRay(const Ray& r, const Interval& ivl, Hit_record& rec) const = 0;
};
