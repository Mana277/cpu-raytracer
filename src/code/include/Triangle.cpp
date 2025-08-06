#include"Triangle.hpp"
#include <iostream>
#include <limits>
#include <cmath>
//--------------------------------
// Constructor implementations
//--------------------------------
Triangle::Triangle(const Point3& A, const Point3& B, const Point3& C, const Color& col, std::shared_ptr<Material> mat):
A_position(A) ,B_position(B) ,C_position(C) , color(col), mat(mat){}

//--------------------------------
// function implementations
//--------------------------------
Point3 Triangle::getA() const{
    return A_position;
}
Point3 Triangle::getB() const{
    return B_position;
}
Point3 Triangle::getC() const{
    return C_position;
}
Color Triangle::getColor() const{
  return color;
}

bool Triangle::hitRay(const Ray& ray, const Interval& ivl, Hit_record& rec) const {

    constexpr float epsilon = std::numeric_limits<float>::epsilon();
    Vec3 ray_vector = ray.getDir();
    Point3 ray_origin = ray.getOrig();
    Vec3 edge1 = B_position - A_position;
    Vec3 edge2 = C_position - A_position;
    Vec3 ray_cross_e2 = cross(ray_vector, edge2);
    float det = dot(edge1, ray_cross_e2);

    if (det > -epsilon && det < epsilon){
        return false;    // This ray is parallel to this triangle.
    }

    float inv_det = 1.0 / det;
    Vec3 s = ray_origin - A_position;
    float u = inv_det * dot(s, ray_cross_e2);

    if ((u < 0 && std::abs(u) > epsilon) || (u > 1 && std::abs(u-1) > epsilon)){
        return false;
    }
    Vec3 s_cross_e1 = cross(s, edge1);
    float v = inv_det * dot(ray_vector, s_cross_e1);

    if ((v < 0 && std::abs(v) > epsilon) || (u + v > 1 && std::abs(u + v - 1) > epsilon)){
        return false;
    }

    // At this stage we can compute t to find out where the intersection point is on the line.
    float t = inv_det * dot(edge2, s_cross_e1);

    if (!ivl.contains(t)){
        return false;
    }
    Vec3 outward_normal = unit_vector(cross(edge1, edge2));
    rec.T = t;
    rec.P = ray.at(t);
    rec.color = color;
    rec.set_face_normal(ray, outward_normal);
    rec.mat = mat;
    return true;
}