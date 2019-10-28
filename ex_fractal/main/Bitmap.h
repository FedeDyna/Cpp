#ifndef BITMAP_H_INCLUDED
#define BITMAP_H_INCLUDED

#include <string>
#include <cstdint> // for unsigned char which declare the rgb colors of each pixel
#include <memory>  //N.B. I need to have this library to use unique_ptr !!!!!!!
using namespace std;

namespace caveofprogramming{

class Bitmap {
    private: // I can put private members refered to width and height of the bitmap here
        int m_width {0}; // I can also declare it as _width TO SHOW ITS PRIVATE MEMBER OF THE CLASS
        int m_height {0}; // i want also initialize them here
        // I write a pointer to hold all the memory i need to
        // write the colors in the heap memory
        // I create a UNIQUE pointer such as I don't need to write delate pointer;
        unique_ptr<uint8_t[]> m_pPixels{nullptr}; // pointer to an array, equivalent to unsigned char

    public:
        Bitmap(int width, int height); // constructor, how bit the bitmap is
        // allow to set (rgb) colors for (x,y)-pixel in the bitmap
        void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue); // uint8_t goes from 0 to 255
        bool write(string filename); // when I create a bitmap, i create pixel and i write on them, i return a bool to have exceptions during debugging, in this way I will have false as return value
        virtual ~Bitmap(); // virtual destructors
};

}

#endif // BITMAP_H_INCLUDED
