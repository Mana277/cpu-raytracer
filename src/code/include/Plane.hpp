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
    Plane(const Point3& plane_orig, const Vec3& normal, const Color& col, std::shared_ptr<Material> mat);

    Point3 getOrig() const;
    Vec3 getNormal() const;
    Color getColor() const;

    bool hitRay(const Ray& r, const Interval& ivl, Hit_record& rec) const override;


  private:
    //member variable
    Point3 plane_origin;
    Vec3 Normal;
    Color color;
    std::shared_ptr<Material> mat;
}; 