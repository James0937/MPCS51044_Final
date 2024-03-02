#include "Image.h"

namespace mpcs51044 {

Image::Image() noexcept: PNG() {}

Image::Image(unsigned width, unsigned height) noexcept: PNG(width, height) {}

// These functions make full use of the template function in PNG class
void Image::lighten(double amount) noexcept {
    modifyPixels([amount](HSLAPixel& pixel) {
        pixel.l = std::min(pixel.l + amount, 1.0);
    });
}

void Image::darken(double amount) noexcept {
    modifyPixels([amount](HSLAPixel& pixel) {
        pixel.l = std::max(pixel.l - amount, 0.0);
    });
}

void Image::saturate(double amount) noexcept {
    modifyPixels([amount](HSLAPixel& pixel) {
        pixel.s = std::min(pixel.s + amount, 1.0);
    });
}

void Image::desaturate(double amount) noexcept {
    modifyPixels([amount](HSLAPixel& pixel) {
        pixel.s = std::max(pixel.s - amount, 0.0);
    });
}

void Image::grayscale() noexcept {
    modifyPixels([](HSLAPixel& pixel) {
        pixel.s = 0;
    });
}

void Image::rotateColor(double degrees) noexcept {
    if (degrees < 0) {
        degrees += 360 * (1 + static_cast<int>(-degrees)/360);
    }
    if (degrees > 360) {
        degrees -= 360 * (static_cast<int>(degrees)/360);
    }
    modifyPixels([degrees](HSLAPixel& pixel) {
        if ((pixel.h += degrees) > 360) {
            pixel.h -= 360;
        }
    });
}

void Image::scale(double factor) noexcept {
    unique_ptr<PNG> old = make_unique<PNG>(*this);
    resize(width() * factor, height() * factor);
    for (unsigned w = 0; w < width(); w++) {
        for (unsigned h = 0; h < height(); h++) {
            HSLAPixel& new_p = getPixel(w, h);
            HSLAPixel& old_p = old->getPixel(
                static_cast<unsigned int>(w / factor),
                static_cast<unsigned int>(h / factor));
            new_p = old_p;
        }
    }
}

void Image::scale(unsigned w, unsigned h) noexcept {
    double factor_w = static_cast<double>(w) / width();
    double factor_h = static_cast<double>(h) / height();
    scale(std::min(factor_w, factor_h));
}
};