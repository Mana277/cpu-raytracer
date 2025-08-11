#include <limits>
#include "Image.hpp"
#include "ImageIO.hpp"
#include "ImageUtils.hpp"
#include "Camera.hpp"
#include "Color.hpp"
#include "Hittable_list.hpp"
#include "Interval.hpp"
#include "Render.hpp"
#include "Sample_Scenes.hpp"

int main() {
    // Constants
    Camera cam;
    Hittable_list world;
    
    //set scenes
    set_scene2(cam, world);

    // Rendering
    Image<double> img = Render(image_width, image_height, c, cam, world);

    // Write output to file
    Image<unsigned char> buffer = convert_to_uchar(img);
    const char* f = "out.png";
    Write_Png(f, buffer);

    return 0;
}