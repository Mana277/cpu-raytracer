#pragma once 
#include <random>
std::mt19937 gen(std::random_device{}());
std::uniform_real_distribution<> dist(0.0, 1.0);

// Header contents

Image<float> Render(int image_width, int image_height, int channnels, const Camera& cam, const Hittable& world) {
    // Constants
    const double infinity = std::numeric_limits<double>::infinity();
    const Interval ray_t(0.0001, infinity);
    const int samples = 5;

    // Class to store pixel color information (normalized)
    Image<float> img(image_width, image_height, 3);
    float* img_vec = img.getImgdata();

    for (int y = 0; y < image_height; y++) {
        for (int x = 0; x < image_width; x++) {
            float r=0, g=0, b=0;
            
            Hit_record rec; // The record should be initialized for each ray
            for(int i=0; i < samples; i++){
                double ram_h = dist(gen);
                double ram_v = dist(gen);
                // Generate ray
                double h = (x+ram_h) / (image_width-1);
                double v = (y+ram_v) / (image_height-1);
                Ray target = cam.getRay(h,v);

                // calculate color
                if (world.hitRay(target, cam.getRay_t(), rec)){
                    Vec3 N_u = rec.N;
                    r += 0.5 * (N_u.x + 1);
                    g += 0.5 * (N_u.y + 1);
                    b += 0.5 * (N_u.z + 1);
                } else {
                    const Vec3 unit_direction = unit_vector(target.getDir());
                    float a = 0.5 * (unit_direction.y + 1.0f);
                    r += 1.0 - 0.5 * a;
                    g += 1.0 - 0.3 * a;
                    b += 1.0;
                }
            }
            r /= samples;
            g /= samples;
            b /= samples;
            // Store color data
            int id = (y * image_width + x) *channnels;
            
            img_vec[id] = r;
            img_vec[id+1] = g;
            img_vec[id+2] = b;
        }
    }

    return img;
};
