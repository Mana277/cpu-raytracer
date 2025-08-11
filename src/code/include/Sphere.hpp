#pragma once 
#include"Vec3.hpp"
#include"Color.hpp"
#include"Ray.hpp"
#include"Hittable.hpp"
#include "Interval.hpp"
#include "Material.hpp"
#include <memory>

// Header contents
class Sphere  : public Hittable{
  public:
    //Constructor 
    Sphere(const Point3& c_pos, float r, std::shared_ptr<Material> mat, const Color& col = Color(1.0, 0.0 , 1.0));

    Point3 getCenter_pos() const;
    float getRadius() const;
    Color getColor() const;

    bool hitRay(const Ray& r, const Interval& ivl, Hit_record& rec) const override;

    

  private:
    //member variable
    Point3 center_position;
    float radius;
    std::shared_ptr<Material> mat;
    Color color;
}; 