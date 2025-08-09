#pragma once 
#include "Color.hpp"
#include "Hittable_list.hpp"
#include "Ray.hpp"
#include "Camera.hpp"
#include "Vec3.hpp"

// Header contents
Color Caluculate_color(const Ray& target, const Camera& cam, const Hittable_list& world, int depth){
    
    if (depth <= 0) {
        return Color(0, 0, 0);
    }

    Hit_record rec;
    
    if (world.hitRay(target, cam.getRay_t(), rec)){
        Ray scattered;
        Color attenuation;

        if (rec.mat->Scatter(target, rec, attenuation, scattered)) {
            return attenuation * Caluculate_color(scattered, cam, world ,depth - 1);
        }

        return Color(0, 0, 0); 
    }else {
        Color color1(1.0, 1.0, 1.0);
        Color color2(0.5, 0.7, 1.0);
        const Vec3 unit_direction = unit_vector(target.getDir());
        double a = 0.5 * (unit_direction.y + 1.0);
        return (1.0-a)*color1 + a*color2;
    }

}
