#pragma once 
#include"Vec3.hpp"
#include"Ray.hpp"
#include "Interval.hpp"
#include "Color.hpp"
// Header contents (class and function declarations)

class Camera {
    public:
        // Constructor 
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
        Point3 origin;
        Point3 Screen_origin;
        Vec3   horizontal;
        Vec3   vertical;
        Interval ray_t;
        Color  background;
}; 
