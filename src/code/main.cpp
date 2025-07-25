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




int main() {
    // Constants
    const double infinity = std::numeric_limits<double>::infinity();
    Hit_record rec;

    // Image settings
    int image_width =1920;  // Test Options: 640, 1920, 7680
    int image_height = 1080; // Test Options: 360, 1080, 4320
    int c = 3; // Number of color channels (RGB)

    // Camera settings
    Interval ray_t(0.0001, infinity);
    Point3 cam_center(0, 0, 0);
    Vec3 cam_dir(0, 0, -1);
    Vec3 cam_up(0, 1, 0);
    double fov_deg = 90;
    double ap = static_cast<double>(image_width) / image_height;
    Camera cam(cam_center, cam_dir, cam_up, fov_deg, ap, ray_t); 

    // World setup
    Hittable_list world;
    world.add(make_shared<Sphere>(Point3(0, -100.5, -1), 100, Color(0.8, 0.8, 0.0), Lambert)); // Green ground sphere
    world.add(make_shared<Sphere>(Point3(0, 0,  -1.2), 0.5, Color(0.1, 0.2, 0.5), Lambert));    
    world.add(make_shared<Sphere>(Point3(-1.0,    0.0, -1.0), 0.5, Color(), Glass));   
    world.add(make_shared<Sphere>(Point3( 1.0,    0.0, -1.0), 0.5, Color(0.8, 0.6, 0.2), Metal(0.5)));     
    

    // Rendering
    Image<double> img = Render(image_width, image_height, c, cam, world);

    // Write output to file
    Image<unsigned char> buffer = convert_to_uchar(img);
    const char* f = "out.png";
    Write_Png(f, buffer);

    return 0;
}


