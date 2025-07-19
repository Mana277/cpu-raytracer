#include "ImageIO.hpp"
#include <stdio.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION 
#include "stb_image_write.h"

//--------------------------------
// function implementations
//--------------------------------
bool Write_Png(const char* filename, const Image<unsigned char>& img){
    const int img_w = img.getWidth();
    const int img_h = img.getHeight();
    const int img_c = img.getChannels(); 
    const unsigned char* img_data = img.getImgdata();

    int stride_in_bytes = img_w * img_c; 

    if (stbi_write_png(filename, img_w, img_h, img_c, img_data, stride_in_bytes)) {
        printf("画像を正常に保存しました（ファイル名: %s)。\n", filename);
        return true;
    } else {
        printf( "画像の保存に失敗しました。\n");
        return false;
    }
};