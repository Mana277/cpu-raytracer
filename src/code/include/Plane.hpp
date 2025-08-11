#pragma once 
#include"Vec3.hpp"
#include"Color.hpp"
#include"Ray.hpp"
#include"Hittable.hpp"
#include "Interval.hpp"
#include "Material.hpp"
#include <memory>

// Header contents
class Plane  : public Hittable{
  public:
    //Constructor 
    Plane(const Point3& plane_orig, const Vec3& normal, std::shared_ptr<Material> mat, const Color& col = Color(1.0, 0.0 , 1.0));

    Point3 getOrig() const;
    Vec3 getNormal() const;
    Color getColor() const;

    bool hitRay(const Ray& r, const Interval& ivl, Hit_record& rec) const override;


  private:
    //member variable
    Point3 plane_origin;
    Vec3 Normal;
    std::shared_ptr<Material> mat;
    Color color;
}; 