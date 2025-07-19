#pragma once 
#include "Vec3.hpp"

// Header contents

class Ray {

  public:

    // Constructor
    Ray();
    Ray(const Point3& orig, const Vec3& dir);

    // member function 
    Point3 getOrig() const;
    Vec3 getDir() const;
    Point3 at(double t) const;

  private:
    //member variable
    Point3 origin;
    Vec3 direction;
}; 