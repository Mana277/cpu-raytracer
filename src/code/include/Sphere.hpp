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
    Sphere(const Point3& c_pos, double r, const Color& col, std::shared_ptr<Material> mat);

    Point3 getCenter_pos() const;
    double getRadius() const;
    Color getColor() const;

    bool hitRay(const Ray& r, const Interval& ivl, Hit_record& rec) const override;

    

  private:
    //member variable
    Point3 center_position;
    double radius;
    Color color;
    std::shared_ptr<Material> mat;
}; 