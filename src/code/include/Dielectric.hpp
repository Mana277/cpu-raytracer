#pragma once 
#include <cmath>
#include <stdio.h>
#include "Material.hpp"
#include "Color.hpp"
#include "Utils.hpp"

// Header contents

class Dielectric : public Material {
    public:
        Dielectric(double n_material) :  n_material(n_material) {}

        bool  Scatter(
            const Ray& r_in,           
            const Hit_record& rec,     
            Color& attenuation,        
            Ray& scattered             
        ) const override {
            Vec3 ray_in_dir = r_in.getDir(); 
            Vec3 ray_in_dir_uni = unit_vector(ray_in_dir);
            Vec3 Normal = rec.N;
            double n_air = 1.0;
            double eta =  rec.front_face ? (n_air/n_material) : (n_material/n_air);
            double cos_in =  std::fmin(dot((-1)*ray_in_dir_uni , Normal), 1.0); 
            double sin_in =  std::sqrt(1-(cos_in*cos_in));
            bool TIR = eta*sin_in > 1;

            if (TIR || reflectance(cos_in, eta) > random(0, 1.0)){
                Vec3 reflected = ray_in_dir - 2 *dot(ray_in_dir ,  Normal)* Normal;
                scattered = Ray(rec.P, reflected);
            }else{
                Vec3 r_out_perp =  eta * (ray_in_dir_uni + cos_in*Normal);
                Vec3 r_out_parallel = (- std::sqrt(std::fabs(1.0 - r_out_perp.length_squared()))) * Normal;
                scattered = Ray(rec.P, r_out_perp +  r_out_parallel);
            }
            attenuation = Color(1.0, 1.0, 1.0);
            return true;
        }
    private:
      double n_material; 
      static double reflectance(double cos, double eta) {
        double R0 = (1-eta) / (1+eta);
        R0 = R0*R0;
        return R0 + (1-R0)*std::pow((1 - cos),5);
      }
  
};