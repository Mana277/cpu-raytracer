#pragma once 
#include"Vec3.hpp"
#include"Color.hpp"
#include"Ray.hpp"
#include"Hittable.hpp"
#include "Interval.hpp"
#include "Material.hpp"
#include <memory>

// Header contents
class Triangle  : public Hittable{
  public:
    //Constructor 
    Triangle(const Point3& A, const Point3& B, const Point3& C, std::shared_ptr<Material> mat,  const Color& col = Color(1.0, 0.0 , 1.0));

    Point3 getA() const;
    Point3 getB() const;
    Point3 getC() const;
    Color getColor() const;

    bool hitRay(const Ray& r, const Interval& ivl, Hit_record& rec) const override;

    

  private:
    //member variable
    Point3 A_position;
    Point3 B_position;
    Point3 C_position;
    std::shared_ptr<Material> mat;
    Color color;
}; 