#include "Camera.hpp"
#include<cmath>

constexpr double pi = 3.141592653589793;
//--------------------------------
// Constructor implementation
//--------------------------------
Camera::Camera(Point3 orig, Vec3 camdir, Vec3 vup, double vfov_deg, double aspect_ratio, Interval rt, Color col): 
origin(orig), ray_t(rt) , background(col) {
    Vec3 dir = camdir - orig;
    Point3  vewpoint_center = orig + unit_vector(dir);
    double half_vfov_rad = (vfov_deg*pi)/360;
    double vewpoint_height = 2 * tan(half_vfov_rad);
    double vewpoint_width =  aspect_ratio*vewpoint_height ;
    horizontal = vewpoint_width*unit_vector(cross(dir, vup));
    vertical = vewpoint_height*unit_vector(cross(dir, horizontal));
    Screen_origin = vewpoint_center - (horizontal/2) - (vertical/2);
}

//--------------------------------
// Member function implementations 
//--------------------------------
Color Camera::getBack() const{
    return background;
}

Ray Camera::getRay(double h, double v) const{
    Point3 pixel_point = Screen_origin + h*horizontal + v*vertical;
    Vec3 ray_dir = pixel_point - origin;
    return Ray(origin, ray_dir);
}

Interval  Camera::getRay_t() const{
    return ray_t;
}
