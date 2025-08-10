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

    if (!world.hitRay(target, cam.getRay_t(), rec)){
        return cam.getBack();
    }

    Ray scattered;
    Color attenuation;
    Color color_emitted = rec.mat->emitted();

    if (!rec.mat->Scatter(target, rec, attenuation, scattered)) {
        return color_emitted;
    }

    Color color_scatter = attenuation * Caluculate_color(scattered, cam, world ,depth - 1);
    return color_emitted + color_scatter;
}