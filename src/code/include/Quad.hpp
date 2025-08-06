#pragma once

#include "Hittable.hpp"
#include "Triangle.hpp" // Triangleクラスを再利用するためインクルード
#include <memory>
#include <vector>

class Quad : public Hittable {
public:
    //Constructor 
    Quad(const Point3& A, const Point3& B, const Point3& C, const Point3& D, const Color& col, std::shared_ptr<Material> mat);

    Point3 getA() const;
    Point3 getB() const;
    Point3 getC() const;
    Point3 getD() const;
    Color getColor() const;

    bool hitRay(const Ray& ray, const Interval& ivl, Hit_record& rec) const override;

private:
    Point3 A_position;
    Point3 B_position;
    Point3 C_position;
    Point3 D_position;
    Color color;
    std::shared_ptr<Material> mat;
    Triangle triangle1;
    Triangle triangle2;
};