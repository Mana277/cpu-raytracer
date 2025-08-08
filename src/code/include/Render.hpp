#pragma once 
#include "Color.hpp"
#include "Ray.hpp"
#include "Vec3.hpp"
#include "Utils.hpp"
#include "Hittable_list.hpp"
#include "Reflection.hpp"
#include "Gamma.hpp"
#include <cstdio>
#include <omp.h>

#include <chrono>
#include <cstdio>
// Header contents


inline Image<double> Render(int image_width, int image_height, int channnels, const Camera& cam, const Hittable_list& world) {

    // Constants
    const double infinity = std::numeric_limits<double>::infinity();
    const Interval ray_t(0.0001, infinity);
    const int samples = 1000;
    const int Max_depth = 50;
    const int samples_per_axis = static_cast<int>(sqrt(samples));
    

    // Class to store pixel color information (normalized)
    Image<double> img(image_width, image_height, 3);
    double* img_vec = img.getImgdata();
    #pragma omp parallel for schedule(guided)
    for (int y = 0; y < image_height; y++) {
        for (int x = 0; x < image_width; x++) {
            Color color(0,0,0);
            
            for (int j = 0; j < samples_per_axis; ++j) {
                for (int i = 0; i < samples_per_axis; ++i) {
                    double ram_h = (static_cast<double>(i) + random(0, 1.0)) / samples_per_axis;
                    double ram_v = (static_cast<double>(j) + random(0, 1.0)) / samples_per_axis;
                    
                    // Generate ray
                    double h = (x+ram_h) / (image_width-1);
                    double v = (y+ram_v) / (image_height-1);
                    Ray target = cam.getRay(h,v);

                    // calculate color
                    color = color + Caluculate_color(target, cam, world, Max_depth);
                }
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
