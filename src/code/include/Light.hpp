#pragma once 

#include "Material.hpp"
#include "Vec3.hpp"
#include "Color.hpp"


// Header contents

class Light : public Material {
    public:
        Light(const Color& c) : emit(c) {}
    
        virtual Color emitted() const override {
            return emit;
        }
    private:
        Color emit;
};