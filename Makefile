EXENAME = mpcs51044final
OBJS += PNG.o HSLAPixel.o lodepng.o
OBJS += Image.o StickerSheet.o main.o

CXX = g++
CXXFLAGS = -std=c++20  -c -g -O0 -Wall -Wextra -pedantic
LD = g++
LDFLAGS = -std=c++20  -lpthread -lm

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

# mpcs51044 
PNG.o : mpcs51044/PNG.cpp mpcs51044/PNG.h mpcs51044/HSLAPixel.h mpcs51044/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) mpcs51044/PNG.cpp

HSLAPixel.o : mpcs51044/HSLAPixel.cpp mpcs51044/HSLAPixel.h
	$(CXX) $(CXXFLAGS) mpcs51044/HSLAPixel.cpp

lodepng.o : mpcs51044/lodepng/lodepng.cpp mpcs51044/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) mpcs51044/lodepng/lodepng.cpp

# main dir
main.o : main.cpp Image.h StickerSheet.h
	$(CXX) $(CXXFLAGS) main.cpp

Image.o : Image.cpp Image.h mpcs51044/PNG.h
	$(CXX) $(CXXFLAGS) Image.cpp

StickerSheet.o : StickerSheet.cpp StickerSheet.h Image.h
	$(CXX) $(CXXFLAGS) StickerSheet.cpp

# helpful
clean :
	-rm -f *.o $(EXENAME) test
