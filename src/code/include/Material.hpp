#pragma once 

#include "Ray.hpp"
#include "Color.hpp"
#include "Vec3.hpp"

// Header contents

class Hit_record; 

class Material {
  public:
    
    virtual ~Material() = default;
    
    virtual Color emitted() const {
      return Color(0,0,0);
    }

    virtual bool Scatter(
        const Ray& r_in,           
        const Hit_record& rec,     
        Color& attenuation,        
        Ray& scattered             
    ) const {
      return false;
    }
};

