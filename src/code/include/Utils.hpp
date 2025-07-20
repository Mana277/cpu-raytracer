#pragma once 
#include <random>

// Header contents (class and function declarations)

inline double random(double min, double max) {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<> dist(min, max);
    return dist(gen);
}