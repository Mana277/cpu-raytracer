#pragma once 

#include "Material.hpp"

// Header contents

class Lambertian : public Material {
    public:
        bool  Scatter(
            const Ray& r_in,           
            const Hit_record& rec,     
            Color& attenuation,        
            Ray& scattered             
        ) const override {
            Vec3 scatter_direction = rec.N + random_unit_vector();
            if (scatter_direction.near_zero()) {
                scatter_direction = rec.N;
            }
    
            scattered = Ray(rec.P, scatter_direction);
            attenuation = rec.color; 
            return true;
        }
  
  };