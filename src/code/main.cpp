#include <vector>
#include <iostream>
#include <limits>
#include "Image.hpp"
#include "ImageIO.hpp"
#include "ImageUtils.hpp"
#include "Camera.hpp"
#include "Color.hpp"
#include "Sphere.hpp"
#include "Hittable.hpp"
#include "Hittable_list.hpp"
#include "Interval.hpp"
#include "Render.hpp"
#include "Material.hpp"
#include "Lambertian.hpp"
#include "Metal.hpp"
#include "Dielectric.hpp"

#define Lambert std::make_shared<Lambertian>()
#define Metal(...) std::make_shared<Metal>(__VA_ARGS__)
#define Glass std::make_shared<Dielectric>(1.5)
#define Airbubble std::make_shared<Dielectric>(1.00 / 1.33)
#define Hollowglass std::make_shared<Dielectric>(1.00 / 1.50)


int main() {
    // Constants
    const double infinity = std::numeric_limits<double>::infinity();
    Hit_record rec;

    // Image settings
    int image_width =  640;  // Test Options: 640, 1920, 7680
    int image_height = 360; // Test Options: 360, 1080, 4320
    int c = 3; // Number of color channels (RGB)

    // Camera settings
    Interval ray_t(0.0001, infinity);
    Point3 cam_center(-2, 2, 1);
    Vec3 cam_dir(0, 0, -1);
    Vec3 cam_up(0, 1, 0);
    double fov_deg = 20;
    double ap = static_cast<double>(image_width) / image_height;
    Camera cam(cam_center, cam_dir, cam_up, fov_deg, ap, ray_t); 

    // World setup
    Hittable_list world;
    world.add(make_shared<Sphere>(Point3( 0.0, -100.5, -1.0), 100, Color(0.8, 0.8, 0.0), Lambert)); 
    world.add(make_shared<Sphere>(Point3( 0.0, 0.0,  -1.2),   0.5, Color(0.1, 0.2, 0.5), Lambert));    
    world.add(make_shared<Sphere>(Point3( 1.0, 0.0, -1.0),    0.5, Color(0.8, 0.6, 0.2), Metal(1))); 
    world.add(make_shared<Sphere>(Point3( 0.0, 0.0, -2.1),    0.5, Color(0.95, 0.64, 0.54), Metal(0.5))); 
    world.add(make_shared<Sphere>(Point3( 0.0, 0.0, 0.1),    0.5, Color(0.97, 0.96, 0.91), Metal(0.0))); 
    world.add(make_shared<Sphere>(Point3( -1.0, 0.0, -1.0),    0.5, Color(0, 0, 0), Glass));         
    world.add(make_shared<Sphere>(Point3( -1.0, 0.0, -1.0),    0.4, Color(0, 0, 0), Hollowglass));

    // Rendering
    Image<double> img = Render(image_width, image_height, c, cam, world);
    // Write output to file
    Image<unsigned char> buffer = convert_to_uchar(img);
    const char* f = "out.png";
    Write_Png(f, buffer);

    return 0;
}






