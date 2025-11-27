#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "../rgb/rgb.h"
#include <vector>
#include <fstream>
#include <string>

class image {
private:
    int width;
    int height;
    std::vector<rgb> pixels;
public:
    image();
    image(const int&, const int&);
    int get_height() const;
    int get_width() const;
    void resize_image(const int&, const int&);
    const std::vector<rgb>& get_pixels() const;
    const rgb& get_pixel_at(const int&, const int&) const;
    void set_pixel_at(const int&, const int&, const rgb&);
    void save_ppm(const std::string&) const;
};

#endif // _IMAGE_H_
