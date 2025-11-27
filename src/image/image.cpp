#include "image.h"

image::image() {
    width = 0;
    height = 0;
}

image::image(const int& w, const int& h) {
    width = w;
    height = h;
    pixels = std::vector<rgb>(w * h);
}

int image::get_height() const {
    return height;
}

int image::get_width() const {
    return width;
}

void image::resize_image(const int& w, const int& h) {
    width = w;
    height = h;
    pixels = std::vector<rgb>(w * h);
}

const std::vector<rgb>& image::get_pixels() const {
    return pixels;
}

const rgb& image::get_pixel_at(const int& j, const int& i) const {
    return pixels[i * width + j];
}

void image::set_pixel_at(const int& j, const int& i, const rgb& color) {
    pixels[i * width + j] = color;
}

void image::save_ppm(const std::string& file_path) const {
    std::ofstream ofs(file_path, std::ios::binary);
    if (!ofs) return;
    ofs << "P6\n" << width << ' ' << height << "\n" << "255\n";
    for (const rgb& pixel : pixels) {
        ofs.put(static_cast<char>(pixel.get(0)));
        ofs.put(static_cast<char>(pixel.get(1)));
        ofs.put(static_cast<char>(pixel.get(2)));
    }
}
