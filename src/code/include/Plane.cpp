#include "Plane.hpp"
#include <limits>
#include <cmath>
//--------------------------------
// Constructor implementations
//--------------------------------
Plane::Plane(const Point3& plane_orig, const Vec3& normal, std::shared_ptr<Material> mat, const Color& col)
    : plane_origin(plane_orig), Normal(unit_vector(normal)), mat(mat), color(col) {} 

//--------------------------------
// function implementations
//--------------------------------
Point3 Plane::getOrig() const{
    return plane_origin;
}
Vec3 Plane::getNormal() const{
    return Normal;
}
Color Plane::getColor() const{
    return color;
}

bool Plane::hitRay(const Ray& ray, const Interval& ivl, Hit_record& rec) const {
    
    constexpr float epsilon = std::numeric_limits<float>::epsilon();
    float denominator = dot(ray.getDir(), Normal);
    
    if (std::abs(denominator) < epsilon) {
        return false;
    }

    float numerator = dot(plane_origin - ray.getOrig(), Normal);
    float t = numerator / denominator;

    if (!ivl.contains(t)) {
        return false;
    }

    
    rec.T = t;
    rec.P = ray.at(t);
    rec.mat = mat;
    rec.color = color; 

    rec.set_face_normal(ray, Normal);

    return true;
}