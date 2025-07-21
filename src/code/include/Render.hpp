#pragma once 
#include "Color.hpp"
#include "Ray.hpp"
#include "Vec3.hpp"
#include "Utils.hpp"
#include "Hittable_list.hpp"
#include <cstdio>

// Header contents
Color Calculate_color(const Ray& target, const Camera& cam, const Hittable_list& world, int depth){
    Hit_record rec;
    if (world.hitRay(target, cam.getRay_t(), rec) && depth >= 0 ){
        Vec3 N_u = random_on_hemisphere(rec.N);
        return 0.5*Calculate_color(Ray(rec.P,N_u), cam,world ,depth - 1);
    } else {
        Color color1(1.0, 1.0, 1.0);
        Color color2(0.5, 0.7, 1.0);
        const Vec3 unit_direction = unit_vector(target.getDir());
        double a = 0.5 * (unit_direction.y + 1.0);
        return (1.0-a)*color1 + a*color2;
    }
};

Image<double> Render(int image_width, int image_height, int channnels, const Camera& cam, const Hittable_list& world) {
    // Constants
    const double infinity = std::numeric_limits<double>::infinity();
    const Interval ray_t(0.0001, infinity);
    const int samples = 5;
    const int Max_depth = 50;
    

    // Class to store pixel color information (normalized)
    Image<double> img(image_width, image_height, 3);
    double* img_vec = img.getImgdata();
    

    for (int y = 0; y < image_height; y++) {
        for (int x = 0; x < image_width; x++) {
            Color color(0,0,0);
            
            for(int i=0; i < samples; i++){
                double ram_h = random(0,1.0);
                double ram_v = random(0,1.0);
                // Generate ray
                double h = (x+ram_h) / (image_width-1);
                double v = (y+ram_v) / (image_height-1);
                Ray target = cam.getRay(h,v);

                // calculate color
                color = color + Calculate_color(target, cam, world, Max_depth);
            }
            color = color / samples;

            // Store color data
            int id = (y * image_width + x) *channnels;
            
            img_vec[id] = color.R;
            img_vec[id+1] = color.G;
            img_vec[id+2] = color.B;
        }
    }

    return img;
};
