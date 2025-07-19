#include "Ray.hpp" // 対応するヘッダーファイルをインクルード

//--------------------------------
//Constructor implementations
//--------------------------------
Ray::Ray() : origin(Point3()), direction(Vec3()) {}
Ray::Ray(const Point3& orig, const Vec3& dir) : origin(orig), direction(dir) {}


//--------------------------------
//member function implementations
//--------------------------------

Point3 Ray::getOrig() const{
    return origin;
}

Vec3 Ray::getDir() const{
    return direction;
}

Point3 Ray::at(double t) const{
    return origin + (t*direction);
}