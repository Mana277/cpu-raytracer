#pragma once 

// Header contents
class Vec3 {
  public:
    //member variable
    union{
      double e[3];
      struct {
          double x, y, z;
      };
    };

    // Constructor
    Vec3();
    Vec3(double x, double y, double z);

    // member function
    double length_squared() const;
    double length() const;
    bool near_zero()const;

}; 
using Point3 = Vec3;



Vec3 operator+(const Vec3& v1, const Vec3& v2);

Vec3 operator-(const Vec3& v1, const Vec3& v2);

Vec3 operator*(double t, const Vec3& v);

Vec3 operator*(const Vec3& v, double t);

Vec3 operator/(const Vec3& v, double t);

double dot(const Vec3& v1, const Vec3& v2);

Vec3 cross(const Vec3& v1, const Vec3& v2);

Vec3 unit_vector(const Vec3& v);

Vec3 random_unit_vector();

Vec3 random_on_hemisphere(const Vec3& normal); 

