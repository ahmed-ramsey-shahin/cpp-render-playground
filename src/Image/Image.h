#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "../RGB/RGB.h"
#include <vector>
#include <fstream>
#include <string>
#include <cmath>

class Image {
private:
    int width;
    int height;
    std::vector<RGB> pixels;
public:
    Image();
    Image(const int&, const int&);
    int get_height() const;
    int get_width() const;
    void resize_image(const int&, const int&);
    const std::vector<RGB>& get_pixels() const;
    const RGB& get_pixel_at(const int&, const int&) const;
    void set_pixel_at(const int&, const int&, const RGB&);
    void save_ppm(const std::string&) const;
};

#endif // _IMAGE_H_
