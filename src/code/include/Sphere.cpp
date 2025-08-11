#include"Sphere.hpp"
#include <iostream>
#include <algorithm> 

//--------------------------------
// Constructor implementations
//--------------------------------
Sphere::Sphere(const Point3& c_pos, float r, std::shared_ptr<Material> mat, const Color& col):
center_position(c_pos), radius(r), mat(mat), color(col){}

//--------------------------------
// function implementations
//--------------------------------
Point3 Sphere::getCenter_pos() const{
  return center_position;
}
float Sphere::getRadius() const{
    return radius;
}
Color Sphere::getColor() const{
  return color;
}

bool Sphere::hitRay(const Ray& ray, const Interval& ivl, Hit_record& rec) const {
  float D; // Discriminant
  float b, a, c; // Temporary variables for discriminant
  Vec3 rayDir = ray.getDir();
  Vec3 co = ray.getOrig() - center_position;

  b = dot(rayDir, co);
  a = rayDir.length_squared();
  c = co.length_squared() - (radius * radius);

  D = (b * b) - (a * c);

  if (D < 0) {
      // No real roots: the ray does not intersect the sphere
      return false;
  }

  float D_sqrt = std::sqrt(D);
  float t = (-b - D_sqrt) / a;
  if (!ivl.contains(t)) {
      // If the smaller root is outside the interval, try the larger one
      t = (-b + D_sqrt) / a;
      if (!ivl.contains(t)) {
          // If both roots are outside the interval, no hit
          return false;
      }
  }

  Point3 Hit_point = ray.at(t);
  Vec3 Normal = unit_vector((Hit_point - center_position) / radius);

  rec.T = t;
  rec.P = Hit_point;
  rec.color = color;
  rec.set_face_normal(ray, Normal);
  rec.mat = mat;
  return true;
}
