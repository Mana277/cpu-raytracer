#pragma once

#include "Hittable.hpp"
#include "Vec3.hpp"
#include <memory>

// Header contents
class Box : public Hittable {
public:
    // Constructor
    Box(const Point3& min_corn, const Point3& max_corn, std::shared_ptr<Material> mat, const Color& col = Color(1.0, 0.0 , 1.0));

    Point3 getMin() const;
    Point3 getMax() const;
    Color getColor() const;
    
    bool hitRay(const Ray& ray, const Interval& ivl, Hit_record& rec) const override;

private:
    //member variable
    Point3 box_min; 
    Point3 box_max; 
    std::shared_ptr<Material> mat;
    Color color;
};