#pragma once 

#include "Ray.hpp"
#include "Color.hpp"

// Header contents

class Hit_record; 

class Material {
  public:
    
    virtual ~Material() = default;


    virtual bool Scatter(
        const Ray& r_in,           
        const Hit_record& rec,     
        Color& attenuation,        
        Ray& scattered             
    ) const = 0;
};

