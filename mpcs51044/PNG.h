#ifndef MPCS_PNG_H
#define MPCS_PNG_H

#include <string>
#include <vector>
#include "HSLAPixel.h"

// The header file of a simple PNG class using HSLAPixels and the lodepng PNG library.
using std::string;
using std::endl;
using std::vector;

namespace mpcs51044 {
  class PNG {
  private:
    unsigned int width_; // Width of the image
    unsigned int height_; // Height of the image
    vector<HSLAPixel> imageData_; // Array of pixels
  public:
    // Creates an empty PNG image.
    PNG() noexcept;

    // Creates a PNG image of the specified dimensions.
    explicit PNG(unsigned int width, unsigned int height) noexcept;  

    // Copy constructor which creates a new PNG image that is a copy of another.
    PNG(PNG const & other) noexcept;

    ~PNG() = default;
  
    // Assignment operator for setting two PNGs equal to one another.
    PNG & operator= (PNG const & other) noexcept;

    // Overloading equality operator: checks if two images are the same.
    bool operator== (PNG const & other) const;

    // Overloading inequality operator: checks if two images are different.
    bool operator!= (PNG const & other) const;

    // Reads in a PNG image from a file.
    // using lodepng
    bool readFromFile(string const & fileName);

    // Writes a PNG image to a file.
    // using lodepng
    bool writeToFile(string const & fileName);

    // Gets a pointer to the pixel at the given coordinates in the image.
    // (0,0) is the upper left corner.
    // It can be used to change the image
    // returning a pointer to an element in a container is still acceptable in modern C++
    // since it's in scenarios where nullability is required
    HSLAPixel& getPixel(unsigned int x, unsigned int y);

    // Return the width of the image.
    unsigned int width() const noexcept;

    // Return the height of the image.
    unsigned int height() const noexcept;

    // Resizes the image to the given coordinates.
    // Attempts to preserve existing pixel data but will crop if necessary.
    void resize(unsigned int newWidth, unsigned int newHeight);
  };
}

#endif
