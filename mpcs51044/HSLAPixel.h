#ifndef MPCS_HSLAPIXEL_H
#define MPCS_HSLAPIXEL_H

#include <iostream>

/*It is the head file of the HSLAPixel class, which is for use in the PNG library.*/
namespace mpcs51044 {
  // The brief intro of HSLA fornat: https://www.w3schools.com/html/html_colors_hsl.asp
  struct HSLAPixel {
  public:
    double h = 0; // Double for the hue of the pixel, in degrees [0, 360]
    double s = 0; // Double for the saturation of the pixel, [0, 1]
    double l = 1.0; // Double for the luminance of the pixel, [0, 1]
    double a = 1.0; // Double for the alpha of the pixel, [0, 1], default to 1.0 for opaque

    // Constructs a default HSLAPixel, which should be opaque and white.
    HSLAPixel() = default;

    // Given hue, saturation, and luminance value, construct an opaque pixel
    explicit HSLAPixel(double hue, double saturation, double luminance) noexcept;

    // Given hue, saturation, luminance and alpha value, construct a pixel
    explicit HSLAPixel(double hue, double saturation, double luminance, double alpha) noexcept;

    // Overloading for convenience
    bool operator== (HSLAPixel const & other) const noexcept;
    bool operator!= (HSLAPixel const & other) const noexcept;
  };
  // Stream operator for convenience
  std::ostream & operator<<(std::ostream & out, HSLAPixel const & pixel);
}

#endif
