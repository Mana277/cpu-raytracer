#include "Vec3.hpp" 
#include <cmath>
#include <iostream>
#include <random>
std::mt19937 gen(std::random_device{}());
std::uniform_real_distribution<> dist(-1.0, 1.0);


//--------------------------------
//Constructor implementations
//--------------------------------
Vec3::Vec3() : x(0), y(0), z(0) {}
Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) {}


//--------------------------------
//function implementations
//--------------------------------

double Vec3::length_squared() const {
    return x*x + y*y + z*z;
}

double Vec3::length() const {
    return std::sqrt(length_squared());
}

Vec3 operator+(const Vec3& v1, const Vec3& v2) {
    return Vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vec3 operator-(const Vec3& v1, const Vec3& v2) {
    return Vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vec3 operator*(double t, const Vec3& v) {
    return Vec3(t * v.x, t * v.y, t * v.z);
}

Vec3 operator*(const Vec3& v, double t) {
    return t * v; 
}

Vec3 operator/(const Vec3& v, double t) {
    return Vec3(v.x / t, v.y / t, v.z / t);
}

double dot(const Vec3& v1, const Vec3& v2) {
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

Vec3 cross(const Vec3& v1, const Vec3& v2) {
    return Vec3(v1.y * v2.z - v1.z * v2.y,
                v1.z * v2.x - v1.x * v2.z,
                v1.x * v2.y - v1.y * v2.x);
}

Vec3 unit_vector(const Vec3& v) {
    double len = v.length_squared();
    constexpr double epsilon = 1e-20; 
    if (len > epsilon) {
        return v / std::sqrt(len);
    } else {
        return Vec3(); 
    }
}

Vec3 random_unit_vector() {
    while (1) {
        double x = dist(gen);
        double y = dist(gen);
        double z = dist(gen);
        Vec3 p(x,y,z);
        double lensq = p.length_squared();
        if (lensq <= 1)
            return p / sqrt(lensq);
    }
}

Vec3 random_on_hemisphere(const Vec3& normal) {
    Vec3 on_unit_sphere = random_unit_vector();
    if (dot(on_unit_sphere, normal) > 0.0){ // In the same hemisphere as the normal
        return on_unit_sphere;
    }else{
        return (-1)*on_unit_sphere;
    }
}