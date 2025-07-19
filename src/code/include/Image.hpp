#pragma once 
#include <vector>

// Header contents (class and function declarations)

template <typename T>
class Image {
  public:
    // Constructor
    Image(const int w, const int h, const int c): 
    width(w), height(h), channels(c), image_data(w*h*c)
    {}

    //member function
    int getWidth() const{
      return width;
    }

    int getHeight() const{
      return height; 
    }

    int getChannels() const{
      return channels;
    }

    const std::vector<T>& getVector() const{
      return image_data;
    }

    const T* getImgdata() const{
      return image_data.data(); 
    }
    
    T* getImgdata(){
      return image_data.data(); 
    }

    const T* getAt(const int x, const int y) const{
        if (x < 0 || x >= width || y < 0 || y >= height) {
            return nullptr;
        }
        return image_data.data()+(y*width + x)*channels; 
    }
    
    T* getAt(const int x, const int y){
        if (x < 0 || x >= width || y < 0 || y >= height) {
            return nullptr;
        }
        return image_data.data()+(y*width + x)*channels; 
    }

  private:
    // プライベートなメンバー（変数や関数）
    int width;
    int height;
    int channels;
    std::vector<T> image_data;// ピクセルの色情報
}; 


