
#pragma once 

#include "Material.hpp"
#include "Vec3.hpp"

// Header contents

class Metal : public Material {
    public:
      Metal(double fuzz) :  fuzz(fuzz < 1 ? fuzz : 1) {}

      bool  Scatter(
          const Ray& r_in,           
          const Hit_record& rec,     
          Color& attenuation,        
          Ray& scattered             
      ) const override {
        Vec3 ray_in_dir = r_in.getDir(); 
        Vec3 Normal = rec.N;
        Vec3 reflected = ray_in_dir - 2 *dot(ray_in_dir ,  Normal)* Normal;

        attenuation = rec.color;
        scattered = Ray(rec.P, reflected + fuzz * random_unit_vector());
        return (dot(scattered.getDir(), rec.N) > 0);
      }

    private:
      double fuzz; 
};

