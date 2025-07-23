#pragma once 
#include "Color.hpp"
#include "Hittable_list.hpp"
#include "Ray.hpp"
#include "Camera.hpp"
#include "Vec3.hpp"

// Header contents
Color Simple_Calculate_color(const Ray& target, const Camera& cam, const Hittable_list& world, int depth){
    Hit_record rec;
    if (depth < 0){
        return Color(0,0,0);
    }

    if (world.hitRay(target, cam.getRay_t(), rec)){
        Vec3 N_u = random_on_hemisphere(rec.N);
        return 0.5*Simple_Calculate_color(Ray(rec.P,N_u), cam,world ,depth - 1);
    } else {
        Color color1(1.0, 1.0, 1.0);
        Color color2(0.5, 0.7, 1.0);
        const Vec3 unit_direction = unit_vector(target.getDir());
        double a = 0.5 * (unit_direction.y + 1.0);
        return (1.0-a)*color1 + a*color2;
    }
};

Color Lambertian_Calculate_color(const Ray& target, const Camera& cam, const Hittable_list& world, int depth){
    Hit_record rec;
    if (depth < 0){
        return Color(0,0,0);
    }
    
    if (world.hitRay(target, cam.getRay_t(), rec)){
        Vec3 N_u = rec.N + random_unit_vector();
        if (N_u.near_zero()) {
            N_u = rec.N;
        }
        return rec.color*Lambertian_Calculate_color(Ray(rec.P,N_u), cam,world ,depth - 1);
    } else {
        Color color1(1.0, 1.0, 1.0);
        Color color2(0.5, 0.7, 1.0);
        const Vec3 unit_direction = unit_vector(target.getDir());
        double a = 0.5 * (unit_direction.y + 1.0);
        return (1.0-a)*color1 + a*color2;
    }
};

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