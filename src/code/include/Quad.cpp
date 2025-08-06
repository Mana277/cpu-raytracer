#include "Quad.hpp"
#include "Triangle.hpp"
#include "Hittable.hpp"
#include <iostream>
#include <limits>
#include <cmath>
//--------------------------------
// Constructor implementations
//--------------------------------
Quad::Quad(const Point3& A, const Point3& B, const Point3& C, const Point3& D, const Color& col, std::shared_ptr<Material> mat):
A_position(A) ,B_position(B) ,C_position(C) ,D_position(D) , color(col), mat(mat), triangle1(Triangle(A,B,C,col,mat)),triangle2(Triangle(A,C,D,col,mat)){}

//--------------------------------
// function implementations
//--------------------------------
Point3 Quad::getA() const{
    return A_position;
}
Point3 Quad::getB() const{
    return B_position;
}
Point3 Quad::getC() const{
    return C_position;
}
Point3 Quad::getD() const{
    return D_position;
}
Color Quad::getColor() const{
  return color;
}


bool Quad::hitRay(const Ray& ray, const Interval& ivl, Hit_record& rec) const {
    Hit_record temp_rec;
    bool hit_anything = false;
    double closest_so_far = ivl.max; 

    if (triangle1.hitRay(ray, Interval(ivl.min, closest_so_far), temp_rec)) {
        hit_anything = true;
        closest_so_far = temp_rec.T; 
        rec = temp_rec;
    }

    if (triangle2.hitRay(ray, Interval(ivl.min, closest_so_far), temp_rec)) {
        hit_anything = true;
        rec = temp_rec; 
    }

    return hit_anything;
}