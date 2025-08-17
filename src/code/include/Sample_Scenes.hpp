#pragma once 

#include <memory>
#include <limits>
#include "Vec3.hpp"
#include "Color.hpp"
#include "Camera.hpp"
#include "Color.hpp"
#include "Hittable_list.hpp"
#include "Interval.hpp"
#include "Sphere.hpp"
#include "Triangle.hpp"
#include "Plane.hpp"
#include "Quad.hpp"
#include "Box.hpp"
#include "Material.hpp"
#include "Lambertian.hpp"
#include "Metal.hpp"
#include "Dielectric.hpp"
#include "Light.hpp"

using namespace std;

#define LAMBERT make_shared<Lambertian>()
#define METAL(...) make_shared<Metal>(__VA_ARGS__)
#define GLASS make_shared<Dielectric>(1.5)
#define AIRBUBBLE make_shared<Dielectric>(1 / 1.33)
#define HOLLOWGLASS make_shared<Dielectric>(1.00 / 1.50)
#define LIGHT make_shared<Light>(Color(4,4,4))
#define BRIGHTLIGHT make_shared<Light>(Color(15,15,15))
#define SUN make_shared<Light>(Color(20,18,16))

// Image settings
constexpr int image_width =  640;  // Test Options: 640, 1920, 7680
constexpr int image_height = 360; // Test Options: 360, 1080, 4320
constexpr int c = 3; // Number of color channels (RGB) ***This change may have a system-wide impact.***


// Header contents

//--------------------------------
//A red sphere and a glass sphere are illuminated by two distinct light sources on a flat surface.
//--------------------------------
void set_scene1(Camera& cam, Hittable_list& world){ 
    const double infinity = std::numeric_limits<double>::infinity();

    // Camera settings
    Point3 cam_center(26,3,6);
    Vec3 cam_dir(0,2,0);
    Vec3 cam_up(0, 1, 0);
    double fov_deg = 20;
    double ap = static_cast<double>(image_width) / image_height;
    Interval ray_t(0.0001, infinity);
    Color cam_back(0,0,0);

    cam = Camera(cam_center, cam_dir, cam_up, fov_deg, ap, ray_t, cam_back); 

    // World setup
    world.add(make_shared<Plane>(
        Point3( 0, 0, 0),
        Vec3( 0, 1.0, 0),
        LAMBERT,
        Color(0.8, 0.8, 0)
    ));
    world.add(make_shared<Sphere>(
        Point3(0,2,0),
        2,
        LAMBERT,
        Color(0.8, 0, 0)
    ));
    world.add(make_shared<Sphere>(
        Point3(0,2,4),
        2,
        AIRBUBBLE
    ));
    world.add(make_shared<Quad>(
        Point3(3, 1, -2),  
        Point3(5, 1, -2),   
        Point3(5, 3, -2),   
        Point3(3, 3, -2),        
        LIGHT           
    ));
    world.add(make_shared<Sphere>(
        Point3(0,8,0),
        2,
        LIGHT 
    ));
};

//--------------------------------
//In a box.
//--------------------------------
void set_scene2(Camera& cam, Hittable_list& world){ 
    const double infinity = std::numeric_limits<double>::infinity();

    // Camera settings
    Point3 cam_center(278, 278, -800);
    Vec3 cam_dir(278, 278, 0);
    Vec3 cam_up(0, 1, 0);
    double fov_deg = 40;
    double ap = static_cast<double>(image_width) / image_height;
    Interval ray_t(0.0001, infinity);
    Color cam_back(0,0,0);

    cam = Camera(cam_center, cam_dir, cam_up, fov_deg, ap, ray_t, cam_back); 


    // World setup
    world.add(make_shared<Quad>(
        Point3(0,0,0),  
        Point3(0,555,0),   
        Point3(0,555,555),   
        Point3(0,0,555),        
        LAMBERT,
        Color(0.65, 0.05, 0.05)           
    ));

    world.add(make_shared<Quad>(
        Point3(555,0,0),  
        Point3(555,555,0),   
        Point3(555,555,555),   
        Point3(555,0,555),        
        LAMBERT,
        Color(0.12, 0.45, 0.15)           
    ));
    
    world.add(make_shared<Quad>(
        Point3(0,0,0),  
        Point3(555,0,0),   
        Point3(555,0,555),   
        Point3(0,0,555),        
        LAMBERT,
        Color(0.73, 0.73, 0.73)           
    ));

    world.add(make_shared<Quad>(
        Point3(555,555,555),  
        Point3(0,555,555),   
        Point3(0,555,0),   
        Point3(555,555,0),        
        LAMBERT,
        Color(0.73, 0.73, 0.73)           
    ));

    world.add(make_shared<Quad>(
        Point3(0,0,555),  
        Point3(555,0,555),   
        Point3(555,555,555),   
        Point3(0,555,555),        
        LAMBERT,
        Color(0.73, 0.73, 0.73)           
    ));

    world.add(make_shared<Box>(
        Point3(265, 0, 295),  
        Point3(430, 330, 460),         
        LAMBERT,
        Color(0.73, 0.73, 0.73)           
    ));

    world.add(make_shared<Box>(
        Point3(130, 0, 65),  
        Point3(295, 165, 230),         
        LAMBERT,
        Color(0.73, 0.73, 0.73)           
    ));

    world.add(make_shared<Quad>(
        Point3(343, 554, 332),  
        Point3(213, 554, 332),   
        Point3(213, 554, 227),   
        Point3(343, 554, 227),        
        BRIGHTLIGHT           
    ));
    
};


//--------------------------------
//Add Sun
//--------------------------------
void set_scene3(Camera& cam, Hittable_list& world){ 
    const double infinity = std::numeric_limits<double>::infinity();

    // Camera settings
    Point3 cam_center(26,3,6);
    Vec3 cam_dir(0,2,0);
    Vec3 cam_up(0, 1, 0);
    double fov_deg = 20;
    double ap = static_cast<double>(image_width) / image_height;
    Interval ray_t(0.0001, infinity);
    Color cam_back(0,0,0);

    cam = Camera(cam_center, cam_dir, cam_up, fov_deg, ap, ray_t, cam_back); 

    // World setup
    world.add(make_shared<Plane>(
        Point3( 0, 0, 0),
        Vec3( 0, 1.0, 0),
        LAMBERT,
        Color(0.8, 0.8, 0)
    ));
    world.add(make_shared<Sphere>(
        Point3(0,2,0),
        2,
        LAMBERT,
        Color(0.1, 0.2, 0.5)
    ));
    world.add(make_shared<Sphere>(
        Point3(2,2,4),
        2,
        METAL(1.0),
        Color(0.8, 0.6, 0.2)
    ));
    world.add(make_shared<Sphere>(
        Point3(-2,2,4),
        2,
        METAL(0.3),
        Color(0.8, 0.8, 0.8)
    ));
    world.add(make_shared<Sphere>(
        Point3(0, 100, -200),
        50,
        SUN
    ));
};