#include "Image.h"

Image::Image() {
    width = 0;
    height = 0;
}

Image::Image(const int& w, const int& h) {
    width = w;
    height = h;
    pixels = std::vector<RGB>(w * h);
}

int Image::get_height() const {
    return height;
}

int Image::get_width() const {
    return width;
}

void Image::resize_image(const int& w, const int& h) {
    width = w;
    height = h;
    pixels = std::vector<RGB>(w * h);
}

const std::vector<RGB>& Image::get_pixels() const {
    return pixels;
}

const RGB& Image::get_pixel_at(const int& j, const int& i) const {
    return pixels[i * width + j];
}

void Image::set_pixel_at(const int& j, const int& i, const RGB& color) {
    pixels[i * width + j] = color;
}

void Image::save_ppm(const std::string& file_path) const {
    std::ofstream ofs(file_path, std::ios::binary);
    if (!ofs) return;
    ofs << "P6\n" << width << ' ' << height << "\n" << "255\n";
    for (const RGB& pixel : pixels) {
        float r = std::min(pixel.get(0) * 255, 255.0f);
        float g = std::min(pixel.get(1) * 255, 255.0f);
        float b = std::min(pixel.get(2) * 255, 255.0f);
        ofs.put(static_cast<unsigned char>(r));
        ofs.put(static_cast<unsigned char>(g));
        ofs.put(static_cast<unsigned char>(b));
    }
}
