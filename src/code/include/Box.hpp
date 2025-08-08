#pragma once

#include "Hittable.hpp"
#include "Vec3.hpp"
#include <memory>

// Header contents
class Box : public Hittable {
public:
    // Constructor
    Box(const Point3& min_corn, const Point3& max_corn, const Color& col, std::shared_ptr<Material> mat);

    Point3 getMin() const;
    Point3 getMax() const;
    Color getColor() const;
    
    bool hitRay(const Ray& ray, const Interval& ivl, Hit_record& rec) const override;

private:
    //member variable
    Point3 box_min; 
    Point3 box_max; 
    Color color;
    std::shared_ptr<Material> mat;
};