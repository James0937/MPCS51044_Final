#include "Image.h"

namespace mpcs51044 {

Image::Image() noexcept: PNG() {}

Image::Image(unsigned width, unsigned height) noexcept: PNG(width, height) {}

// void Image::lighten(double amount) {
//     for (auto& pixel : imageData_) {
//         if (pixel.l + amount > 1) pixel.l = 1;
//         else pixel.l += amount;
//     }
// }

void Image::lighten(double amount) {
    for (unsigned w = 0; w < width(); w++) {
        for (unsigned h = 0; h < height(); h++) {
            HSLAPixel& p = getPixel(w, h);
            if ((p.l += amount) > 1) {
                p.l = 1;
            }
        }
    }
}

void Image::darken(double amount) {
    for (unsigned w = 0; w < width(); w++) {
        for (unsigned h = 0; h < height(); h++) {
            HSLAPixel& p = getPixel(w, h);
            if ((p.l -= amount) < 0) {
                p.l = 0;
            }
        }
    }
}

void Image::saturate(double amount) {
    for (unsigned w = 0; w < width(); w++) {
        for (unsigned h = 0; h < height(); h++) {
            HSLAPixel& p = getPixel(w, h);
            if ((p.s += amount) > 1) {
                p.s = 1;
            }
        }
    }
}

void Image::desaturate(double amount) {
    for (unsigned w = 0; w < width(); w++) {
        for (unsigned h = 0; h < height(); h++) {
            HSLAPixel& p = getPixel(w, h);
            if ((p.s -= amount) < 0) {
                p.s = 0;
            }
        }
    }
}

void Image::grayscale() {
    for (unsigned w = 0; w < width(); w++) {
        for (unsigned h = 0; h < height(); h++) {
            getPixel(w, h).s = 0;
        }
    }
}

void Image::rotateColor(double degrees) {
    // std::cout << "Ori degrees: " << degrees;
    if (degrees < 0) {
        degrees += 360 * (1 + int(-degrees)/360);
    }
    if (degrees > 360) {
        degrees -= 360 * (int(degrees) / 360);
    }
    // std::cout << " | New degrees: " << degrees << std::endl;
    for (unsigned w = 0; w < width(); w++) {
        for (unsigned h = 0; h < height(); h++) {
            HSLAPixel& p = getPixel(w, h);
            if ((p.h += degrees) > 360) {
                p.h -= 360;
            }
        }
    }
}

void Image::scale(double factor) {
    PNG* old = new PNG(*this);
    resize(width() * factor, height() * factor);
    for (unsigned w = 0; w < width(); w++) {
        for (unsigned h = 0; h < height(); h++) {
            HSLAPixel& new_p = getPixel(w, h);
            HSLAPixel& old_p = old->getPixel(w / factor, h / factor);
            new_p = old_p;
        }
    }
    delete old;
    old = nullptr;
}

void Image::scale(unsigned w, unsigned h) {
    double factor_w = double(w) / width();
    double factor_h = double(h) / height();
    scale(factor_w > factor_h ? factor_h : factor_w);
}

};