#include <iostream>
#include <string>
#include <algorithm>
#include "lodepng/lodepng.h"
#include "PNG.h"
#include "RGB_HSL.h"

// The implementation of a simple PNG class using HSLAPixels and the lodepng PNG library.
namespace mpcs51044 {
  PNG::PNG() noexcept: width_(0), height_(0), imageData_(){}

  PNG::PNG(unsigned int width, unsigned int height) noexcept {
    width_ = width;
    height_ = height;
    imageData_ = vector<HSLAPixel>(width * height);
  }

  PNG::PNG(PNG const & other) noexcept {
    width_ = other.width_;
    height_ = other.height_;
    imageData_ = other.imageData_;
  }

  PNG & PNG::operator=(PNG const & other) noexcept {
      if (this != &other) {
          width_ = other.width_;
          height_ = other.height_;
          imageData_ = other.imageData_;
      }
      return *this;
  }

  bool PNG::operator== (PNG const & other) const {
    if (width_ != other.width_ || height_ != other.height_) 
      return false;
    
    for (unsigned i = 0; i < width_ * height_; i++) {
      // Alias for more convenient typing :)
      const HSLAPixel& p1 = imageData_[i];
      const HSLAPixel& p2 = other.imageData_[i];

      if (p1.h != p2.h || p1.s != p2.s || p1.l != p2.l || p1.a != p2.a) 
      return false;
    }
    return true;
  }

  bool PNG::operator!= (PNG const & other) const {
    return !(*this == other);
  }

  HSLAPixel * PNG::getPixel(unsigned int x, unsigned int y) {
    // boundary check
    if (width_ == 0 || height_ == 0) {
      cerr << "ERROR: Call to mpcs51044::PNG::getPixel() made on an image with no pixels." << endl;
      cerr << "     : Returning NULL." << endl;
      return NULL;
    }
    if (x >= width_ || y >= height_) {
        throw std::out_of_range("Attempt to access pixel out of bounds.");
    }
    
    return &imageData_[x + y * width_];
  }

  bool PNG::readFromFile(string const & fileName) {
    vector<unsigned char> byteData;
    unsigned error = lodepng::decode(byteData, width_, height_, fileName);

    if (error) {
      cerr << "PNG decoder error " << error << ": " << lodepng_error_text(error) << endl;
      return false;
    }

    imageData_ = vector<HSLAPixel>(width_ * height_);

    for (unsigned i = 0; i < byteData.size(); i += 4) {
      rgbaColor rgb;
      rgb.r = byteData[i];
      rgb.g = byteData[i + 1];
      rgb.b = byteData[i + 2];
      rgb.a = byteData[i + 3];

      hslaColor hsl = rgb2hsl(rgb);
      imageData_[i/4] = HSLAPixel(hsl.h, hsl.s, hsl.l, hsl.a);
    }

    return true;
  }

  bool PNG::writeToFile(string const & fileName) {
    vector<unsigned char> byteData(width_ * height_ * 4);

    for (unsigned i = 0; i < width_ * height_; i++) {
      hslaColor hsl;
      hsl.h = imageData_[i].h;
      hsl.s = imageData_[i].s;
      hsl.l = imageData_[i].l;
      hsl.a = imageData_[i].a;

      rgbaColor rgb = hsl2rgb(hsl);

      byteData[4*i] = rgb.r;
      byteData[4*i + 1] = rgb.g;
      byteData[4*i + 2] = rgb.b;
      byteData[4*i + 3] = rgb.a;
    }

    unsigned error = lodepng::encode(fileName, byteData.data(), width_, height_);
    if (error) {
      cerr << "PNG encoding error " << error << ": " << lodepng_error_text(error) << endl;
    }

    return (error == 0);
  }

  unsigned int PNG::width() const noexcept{
    return width_;
  } 

  unsigned int PNG::height() const noexcept{
    return height_;
  } 

  void PNG::resize(unsigned int newWidth, unsigned int newHeight) {
    // Create a new vector to store the image data for the new (resized) image
    vector<HSLAPixel> newImageData(newWidth * newHeight);

    // Copy the current data to the new image data, using the existing pixel
    // For coordinates within the bounds of the old image size
    for (unsigned x = 0; x < newWidth; x++) {
      for (unsigned y = 0; y < newHeight; y++) {
        if (x < width_ && y < height_) {
          newImageData[y * newWidth + x] = *getPixel(x, y);
        }
      }
    }

    // Update the image to reflect the new image size and data
    width_ = newWidth;
    height_ = newHeight;
    imageData_ = newImageData;
  }
}