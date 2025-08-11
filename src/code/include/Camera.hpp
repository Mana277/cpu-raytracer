#pragma once 
#include"Vec3.hpp"
#include"Ray.hpp"
#include "Interval.hpp"
#include "Color.hpp"
// Header contents (class and function declarations)

class Camera {
    public:
        // Constructor
        Camera() = default; 
        Camera(
            Point3 orig,
            Vec3 camdir,
            Vec3   vup, 
            double vfov_deg, 
            double aspect_ratio,
            Interval rt,
            Color col
        );
        
        // member function
        Color getBack() const;
        Interval getRay_t() const;
        Ray getRay(double h, double v) const; 
    
    private:
        //member variable
        Point3 origin = Point3(0,0,0);  
        Point3 Screen_origin = Point3(0,0,0);
        Vec3 horizontal = Vec3(1,0,0);
        Vec3 vertical = Vec3(0,1,0);
        Interval ray_t = Interval(0.0, 1.0);
        Color background = Color(0.0, 0.0, 0.0);
}; 
