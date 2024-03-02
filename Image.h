#ifndef MPCS_Image_H
#define MPCS_Image_H

#include <memory>
#include "mpcs51044/PNG.h"

using std::unique_ptr;
using std::make_unique;

namespace mpcs51044 {
/* Image class is inherited from the PNG class
* Merely support sticker is boring, isn't it?
* So I add some new features for Image Processing */
// I don't implement function override here
class Image : public PNG {
public:
    // The default constructor
    // We use the constructor of PNG class for Image
    Image() noexcept;

    // The ususal constructor
    // Also use the PNG one
    explicit Image(unsigned width, unsigned height) noexcept;

    // Make an image much lighter than before
    // Based on the definition of HSLA, we change the value of luminance
    // The maximum boundary is "1.0"
    void lighten(double amount = 0.1) noexcept;

    // Make an image much darker than before
    // Based on the definition of HSLA, we change the value of luminance
    // The minimum boundary is "0.0"
    void darken(double amount = 0.1) noexcept;

    // Saturates an Image
    // Based on the definition of HSLA, we change the value of saturation
    // The maximum boundary is "1.0"
    void saturate(double amount = 0.1) noexcept;

    // Desaturates an Image
    // Based on the definition of HSLA, we change the value of saturation
    // The minimum boundary is "0.0"
    void desaturate(double amount = 0.1) noexcept;

    // Turns the image grayscale
    // Based on the definition of HSLA
    // We make the value of saturation be 0.0
    void grayscale() noexcept;

    // Rotates the color wheel by degrees
    // We change the value of hue with degrees
    // It remains in the range [0,360]
    void rotateColor(double degrees) noexcept;

    // Scales the Image by a given factor
    // This function both resizes the Image and scales the contents
    void scale(double factor) noexcept;

    // Scales the image to fit within the size (w x h)
    // This function preserves the aspect ratio of the image
    void scale(unsigned w, unsigned h) noexcept;
};

};

#endif