#ifndef MPCS_PNG_H
#define MPCS_PNG_H

#include <string>
#include <vector>
#include "HSLAPixel.h"

// The header file of a simple PNG class using HSLAPixels and the lodepng PNG library.
using namespace std;

namespace mpcs51044 {
  class PNG {
  private:
    unsigned int width_; // Width of the image
    unsigned int height_; // Height of the image
    HSLAPixel *imageData_; // Array of pixels

    // Helper function for copy
    void _copy(PNG const & other);
  
  public:
    // Creates an empty PNG image.
    PNG();

    // Creates a PNG image of the specified dimensions.
    PNG(unsigned int width, unsigned int height);  

    // Copy constructor which creates a new PNG image that is a copy of another.
    // I think this function is mandatory, and that's why I don't use unique_ptr.
    PNG(PNG const & other);

    /**
      * Destructor: frees all memory associated with a given PNG object.
      * Invoked by the system.
      */
    ~PNG();
  
    // Assignment operator for setting two PNGs equal to one another.
    PNG const & operator= (PNG const & other);

    // Overloading equality operator: checks if two images are the same.
    bool operator== (PNG const & other) const;

    // Overloading inequality operator: checks if two images are different.
    bool operator!= (PNG const & other) const;

    // Reads in a PNG image from a file.
    bool readFromFile(string const & fileName);

    // Writes a PNG image to a file.
    bool writeToFile(string const & fileName);

    // Gets a pointer to the pixel at the given coordinates in the image.
    // (0,0) is the upper left corner.
    // It can be used to change the image.
    HSLAPixel* getPixel(unsigned int x, unsigned int y);

    // Return the width of the image.
    unsigned int width() const;

    // Return the height of the image.
    unsigned int height() const;

    // Resizes the image to the given coordinates.
    // Attempts to preserve existing pixel data but will crop if necessary.
    void resize(unsigned int newWidth, unsigned int newHeight);
  };
}

#endif
