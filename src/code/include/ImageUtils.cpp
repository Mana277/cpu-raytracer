#include "ImageUtils.hpp"

//--------------------------------
//member function implementations
//--------------------------------
Image<unsigned char> convert_to_uchar(const Image<double>& double_img){
    const int img_w = double_img.getWidth();
    const int img_h = double_img.getHeight();
    const int img_c = double_img.getChannels(); 
    const double* double_data = double_img.getImgdata();

    Image<unsigned char> uchar_img(img_w, img_h, img_c);
    unsigned char* uchar_data = uchar_img.getImgdata();
    int x, y, c;
    for(y=0; y<img_h; y++){
        for(x=0; x<img_w; x++){
            int index = (y * img_w + x) * img_c;
            for(c=0; c<img_c; c++){
                double norm_val = double_data[index+c];
                int quant_val = static_cast<int>(255.999 * norm_val);
                uchar_data[index+c] = static_cast<unsigned char>(quant_val);
            }
        }
    }
    return uchar_img;
};