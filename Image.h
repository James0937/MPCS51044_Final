#ifndef MPCS_Image_H
#define MPCS_Image_H

#include "mpcs51044/PNG.h"

namespace mpcs51044 {
/* Image class is inherited from the PNG class
* Merely support sticker is boring, isn't it?
* So I add some new features for Image Processing */
class Image : public PNG {
// private:
//     unsigned int width_; // Width of the image
//     unsigned int height_; // Height of the image
//     vector<HSLAPixel> imageData_; // Array of pixels
public:
    // The default constructor
    // We use the constructor of PNG class for Image
    Image() noexcept;

    // The ususal constructor
    // Also use the PNG one
    explicit Image(unsigned width, unsigned height) noexcept;

    // Make the image much lighter than before
    // Based on the definition of HSLA, we change the value of luminance
    // The maximum boundary is "1.0"
    void lighten(double amount = 0.1);

    // Make the image much darker than before
    // Based on the definition of HSLA, we change the value of luminance
    // The maximum boundary is "1.0"
    void darken(double amount = 0.1);

    /**
     * Saturates an Image by increasing the saturation of every pixel by amount.
     * This function ensures that the saturation remains in the range [0, 1].
     * @param amount    The desired increase in saturation.
     */
    void saturate(double amount = 0.1);

    /**
     * Desaturates an Image by decreasing the saturation of every pixel by amount.
     * This function ensures that the saturation remains in the range [0, 1].
     * @param amount    The desired decrease in saturation.
     */
    void desaturate(double amount = 0.1);

    /**
     * Turns the image grayscale.
     */
    void grayscale();

    /**
     * Rotates the color wheel by degrees.
     * This function ensures that the hue remains in the range [0, 360].
     * @param degrees   The desired amount of rotation.
     */
    void rotateColor(double degrees);

    /**
     * Scales the Image by a given factor.
     * This function both resizes the Image and scales the contents.
     * @param factor    Scale factor.
     */
    void scale(double factor);

    /**
     * Scales the image to fit within the size (w x h).
     * This function preserves the aspect ratio of the image,
     * so the result will always be an image of width w or of height h (not necessarily both).
     * @param w Desired width of the scaled Iamge
     * @param h Desired height of the scaled Image
     */
    void scale(unsigned w, unsigned h);
};

};

#endif