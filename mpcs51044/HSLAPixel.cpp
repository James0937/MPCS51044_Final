#include "HSLAPixel.h"

/*It is the implementation of the HSLAPixel class for use in the PNG library.*/
namespace mpcs51044 {
  HSLAPixel::HSLAPixel(): h(0), s(0), l(1.0), a(1.0) {}

  HSLAPixel::HSLAPixel(double hue, double saturation, double luminance) {
    h = hue;
    s = saturation;
    l = luminance;
    a = 1.0;
  }

  HSLAPixel::HSLAPixel(double hue, double saturation, double luminance, double alpha) {
    h = hue;
    s = saturation;
    l = luminance;
    a = alpha;
  }

  bool HSLAPixel::operator== (HSLAPixel const & other) const {
    // The logic is shown in the website
    if (a != other.a) { return false; }
    if ( a == 0 ) { return true; }

    if (l != other.l) { return false; }
    if (l == 0 || l == 1) { return true; }

    if (s != other.s) { return false; }
    if (s == 0) { return true; }

    return (h == other.h);
  }

  bool HSLAPixel::operator!= (HSLAPixel const & other) const {
    return !(*this == other);
  }

  std::ostream & operator<<(std::ostream & out, HSLAPixel const & pixel) {
    out << "(" << pixel.h << ", " << pixel.s << ", " << pixel.l << (pixel.a != 1 ? ", " + std::to_string(pixel.a) : "") << ")";

    return out;
  }

}
 