#include "Box.hpp"
#include <algorithm> 
#include <cmath>
//--------------------------------
// Constructor implementation
//--------------------------------
Box::Box(const Point3& min_corn, const Point3& max_corn, std::shared_ptr<Material> mat, const Color& col)
    : box_min(min_corn), box_max(max_corn), mat(mat), color(col) {}

//--------------------------------
// function implementations
//--------------------------------
Point3 Box::getMin() const{
    return box_min;
}
Point3 Box::getMax() const{
    return box_max;
}
Color Box::getColor() const{
  return color;
}

bool Box::hitRay(const Ray& ray, const Interval& ivl, Hit_record& rec) const {
    double t_min = ivl.min;
    double t_max = ivl.max;

    Point3 ray_origin = ray.getOrig();
    Vec3 ray_direction = ray.getDir();

    for (int axis = 0; axis < 3; ++axis) {
        double invD = 1.0 / ray_direction.e[axis];
        double t0 = (box_min.e[axis] - ray_origin.e[axis]) * invD;
        double t1 = (box_max.e[axis] - ray_origin.e[axis]) * invD;

        // Ensure t0 is the intersection with the "nearer" plane.
        if (invD < 0.0) {
            std::swap(t0, t1);
        }

        // Update the overall intersection interval.
        t_min = std::max(t_min, t0);
        t_max = std::min(t_max, t1);

        // If the intervals do not overlap, the ray misses the box.
        if (t_min >= t_max) {
            return false;
        }
    }
    
    const double epsilon = 1e-5;
    Point3 outward_normal;

    if (std::abs(rec.P.x - box_min.x) < epsilon) {
        outward_normal = Point3(-1, 0, 0);
    } else if (std::abs(rec.P.x - box_max.x) < epsilon) {
        outward_normal = Point3(1, 0, 0);
    } else if (std::abs(rec.P.y - box_min.y) < epsilon) {
        outward_normal = Point3(0, -1, 0);
    } else if (std::abs(rec.P.y - box_max.y) < epsilon) {
        outward_normal = Point3(0, 1, 0);
    } else if (std::abs(rec.P.z - box_min.z) < epsilon) {
        outward_normal = Point3(0, 0, -1);
    } else {
        outward_normal = Point3(0, 0, 1);
    }

    
    rec.T = t_min;
    rec.P = ray.at(t_min);
    rec.color = color;
    rec.set_face_normal(ray, outward_normal);
    rec.mat = mat;

    return true;
}