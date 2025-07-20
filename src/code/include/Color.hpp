#pragma once 

// Header contents (class and function declarations)

class Color {
public:
  // member variable
  double R;
  double G;
  double B;
  // Constructor
  Color(double r, double g, double b);
}; 


Color operator+(const Color& c1, const Color& c2);

Color operator-(const Color& c1, const Color& c2);

Color operator*(double t, const Color& c);

Color operator*(const Color& c, double t);

Color operator/(const Color& c, double t);