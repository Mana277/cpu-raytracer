#pragma once 
#include "Color.hpp"
#include "Ray.hpp"
#include "Vec3.hpp"
#include "Utils.hpp"
#include "Hittable_list.hpp"
#include "Reflection.hpp"
#include "Gamma.hpp"
#include <cstdio>

// Header contents


inline Image<double> Render(int image_width, int image_height, int channnels, const Camera& cam, const Hittable_list& world) {
    // Constants
    const double infinity = std::numeric_limits<double>::infinity();
    const Interval ray_t(0.0001, infinity);
    const int samples = 1000;
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
                color = color + Caluculate_color(target, cam, world, Max_depth);
            }
            color = color / samples;
            color = GammaCorrection(color, 2.0);
            // Store color data
            int id = (y * image_width + x) *channnels;
            
            img_vec[id] = color.R;
            img_vec[id+1] = color.G;
            img_vec[id+2] = color.B;
        }
    }

    return img;
};
