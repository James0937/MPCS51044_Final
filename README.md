This is my final project for the course "MPCS 51044	C/C++ for Advanced Programmers".

# Intro to the Project Features
This is a figure-processing project. By copying images into the ./Final dir and modifying the "main.cpp", users can insert some stickers on a base image with adjusting their image appearence if wanted (like lighten/darken, saturate, change scale, etc.). The example usage with input figures, output figures, and the code snippets I use are all provided. I/O figures are in the "./Final" dir, and the code snippets are inside the "main.cpp" file as comments.

# How to Use It 
tbd...
1. Copy 
2. Modify the "main.cpp" depends on 
3. Change your pwd into "./Final", and then type
    make
4. Then your 

# Intro to modern C++ elements in my implementation
I applyed these knowledges into my project:
* noexcept keyword for functions which won't raise an error
* explicit keyword for some constructors
* make_unique and unique_ptr for image processing
* template function in PNG class
* using vector as a container for image data

# Intro to Every File
## Inside the dir "mpcs51044"
lodepng: In this dictionary, I download an open-source code snippet from "https://lodev.org/lodepng/". Generally speaking, it's a library for loading the images. It doesn't implement in the modern C++ style, please just omit it.

HSLAPixel: This is a helper class for the pixel processing function (which is in the PNG library). I use HSLA instead of RPG because of extra practicing. RGB Processing seems to ordinary these days.

RGB_HSL: The helper file for transforming RGB format color into the HSLA format. The reason is lodepng is using the RGB format.

PNG: A class using the above libraries for image processing. I build a template function here for convenience in the further class implementation.

## In the main dir "Final"
Image: It's a class inherited from the PNG class. I separate it from the PNG class for obeying the SOLID principle, mainly the "Single Responsibility Principle". This class includes all of the image processing function I wrote, and it uses the template function I wrote in the PNG class.

StickerSheet: tbd
