This is my final project for the course "MPCS 51044	C/C++ for Advanced Programmers".

tip: please mention, the input picture must be in PNG format!

# Intro to the Project Features
This is a figure-processing project. By copying images into the "./Final" dir and modifying the "main.cpp", users can insert some stickers on a base image by adjusting their image appearance if wanted (like lighten/darken, saturate, change scale, etc.). The example usage with input figures, output figures, and the code snippets I use are all provided. I/O figures are in the "./Final" dir, and the code snippets are inside the "main.cpp" file as comments.

# How to Use It 
These are the steps for using my project
1. Copy the pictures you like into the "./Final" dir.
2. Modify the "main.cpp" with the function explanation in .h file or mimicing the comments.
3. Change your pwd into "./Final", and then type:
```bash
    make; ./mpcs51044final
```
4. Then your figure will generate (I hope it goes well).
5. If you want to create another picture, please type:
```bash
    make clean
```
Before the next execution.

Also, you can don't play sticker but just use the function in the Image class to modify the input figure (like lighten/darken, saturate, change scale, etc.). This part is easy to understand, so just refer to the comments in main.cpp.

# Intro to modern C++ elements in my implementation
I applied these knowledges to my project:
* noexcept keyword for functions that won't raise an error
* explicit keyword for some constructors
* make_unique and unique_ptr for image processing
* template function in PNG class
* using vector as a container for image data
* using stdexpect to handle the error
* build move constructors and move assignment operators for some classes
* using mutex and lock_guard for thread safety
* using std::format for error display

# Intro to Every File
## Inside the dir "mpcs51044"
lodepng: In this dictionary, I download an open-source code snippet from "https://lodev.org/lodepng/". Generally speaking, it's a library for loading the images. It doesn't implement in the modern C++ style, please just omit it.

HSLAPixel: This is a helper class for the pixel processing function (which is in the PNG library). I use HSLA instead of RPG because of extra practice. RGB Processing seems to be ordinary these days.

RGB_HSL: The helper file for transforming RGB format color into the HSLA format. The reason is lodepng is using the RGB format.

PNG: A class using the above libraries for image processing. I build a template function here for convenience in the further class implementation.

## In the main dir "Final"
Image: It's a class inherited from the PNG class. I separate it from the PNG class for obeying the SOLID principle, mainly the "Single Responsibility Principle". This class includes all of the image processing functions I wrote, and it uses the template function I wrote in the PNG class.

StickerSheet: It's the core class for picture sticking. I also add threads in this class.

## Write in the last
I really enjoy this course and I believe I learned a lot! Thank you for the effort you have put into teaching the course. I really appreciate it.
And also, I hope you like my sticker drawing "cpp_and_mike.png" :) 
