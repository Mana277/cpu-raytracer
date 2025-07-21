#pragma once
#include "Color.hpp"
#include <algorithm>
#include <cmath>

// Header contents
inline float gammaCorrect(float value, float invGamma) {
    value = std::max(value, 0.0f);
    return std::pow(value, invGamma);
}

inline Color GammaCorrection(const Color& linearColor, float gamma = 2.2f) {
    float invGamma = 1.0f / gamma;
    return Color(
        gammaCorrect(linearColor.R, invGamma),
        gammaCorrect(linearColor.G, invGamma),
        gammaCorrect(linearColor.B, invGamma)
    );
}
