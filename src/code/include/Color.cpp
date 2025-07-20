#include "Color.hpp"

//--------------------------------
//Constructor implementations
//--------------------------------
Color::Color(double r, double g, double b) : R(r), G(g), B(b) {}

//--------------------------------
//function implementations
//--------------------------------

Color operator+(const Color& c1, const Color& c2) {
    return Color(c1.R + c2.R, c1.G + c2.G, c1.B + c2.B);
}

Color operator-(const Color& c1, const Color& c2) {
    return Color(c1.R - c2.R, c1.G - c2.G, c1.B - c2.B);
}

Color operator*(double t, const Color& c) {
    return Color(t * c.R, t * c.G, t * c.B);
}

Color operator*(const Color& c, double t) {
    return t * c; 
}

Color operator/(const Color& c, double t) {
    return Color(c.R / t, c.G / t, c.B / t);
}