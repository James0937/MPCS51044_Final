This is my final project for the course "MPCS 51044	C/C++ for Advanced Programmers".

# Intro to the Project Features
tbd...

# How to Use It
tbd...

# Intro to Every File
## Inside the dir "mpcs51044"
lodepng: In this dictionary, I download an open-source code snippet from "https://lodev.org/lodepng/". Generally speaking, it's a library for loading the images. It doesn't implement in the modern C++ style, please just omit it.

HSLAPixel: This is a helper class for the pixel processing function (which is in the PNG library). I use HSLA instead of RPG because of extra practicing. RGB Processing seems to ordinary these days.

RGB_HSL: The helper file for transforming RGB format color into the HSLA format. The reason is lodepng is using the RGB format.

PNG: A class using the above libraries for image processing. I build a template function here for convenience in the further class implementation.

## In the main dir "Final"
Image: It's a class inherited from the PNG class. I separate it from the PNG class for obeying the SOLID principle, mainly the "Single Responsibility Principle". This class includes all of the image processing function I wrote, and it uses the template function I wrote in the PNG class.

StickerSheet: tbd
