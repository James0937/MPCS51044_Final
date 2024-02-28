#ifndef MPCS_HSLAPIXEL_H
#define MPCS_HSLAPIXEL_H

#include <iostream>

/*It is the head file of the HSLAPixel class, which is for use in the PNG library.*/
namespace mpcs51044 {
  // The brief intro of HSLA fornat: https://www.w3schools.com/html/html_colors_hsl.asp
  class HSLAPixel {
  public:
    double h; // Double for the hue of the pixel, in degrees [0, 360]
    double s; // Double for the saturation of the pixel, [0, 1]
    double l; // Double for the luminance of the pixel, [0, 1]
    double a; // Double for the alpha of the pixel, [0, 1]

    // Constructs a default HSLAPixel, which should be opaque and white.
    HSLAPixel();

    // Given hue, saturation, and luminance value, construct an opaque pixel
    HSLAPixel(double hue, double saturation, double luminance);

    // Given hue, saturation, luminance and alpha value, construct a pixel
    HSLAPixel(double hue, double saturation, double luminance, double alpha);

    // Overloading for convenience
    bool operator== (HSLAPixel const & other) const ;
    bool operator!= (HSLAPixel const & other) const ;
  };
  // Stream operator for convenience
  std::ostream & operator<<(std::ostream & out, HSLAPixel const & pixel);
}

#endif
 