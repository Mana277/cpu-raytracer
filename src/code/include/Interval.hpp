#pragma once 
#include <limits>
const double infinity = std::numeric_limits<double>::infinity();
// Header contents

class Interval {
    public:
    
    //member variable
    double min, max;
    //Constructor
    Interval(): min(infinity), max(-infinity){}
    Interval(double min, double max):min(min), max(max){}

    bool contains(double x) const {
        return min <= x && x <= max;
    }

    bool surrounds(double x) const {
        return min < x && x < max;
    }
}; 