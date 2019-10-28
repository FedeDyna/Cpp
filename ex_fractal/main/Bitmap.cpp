
#include <fstream>// to write a binary file and then put the bitmap on it
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace caveofprogramming; // because I have the two included inside this namespace, and I don't
// want to use caveofprogramming: for all the struc and classes
using namespace std;

namespace caveofprogramming{

// constructor, with initializations , last value is for initialize the color pointer
Bitmap::Bitmap(int width, int height):
        m_width(width), m_height(height), m_pPixels(
                new uint8_t[width*height*3]{}) {


}

// function member of the class Bitmap
bool Bitmap::write(string filename){
     // create the functions
    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;
    // the size of the file                                                      // actual size of the file, m_* are set by the constructor
    fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader)
            + (m_width*m_height*3);
    fileHeader.dataOffset =  sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);//

    // infoHeader contains info about the bitmap
    infoHeader.width = m_width;
    infoHeader.height = m_height;

    // create a binary output file
    ofstream file;
    file.open(filename, ios::out|ios::binary);
    // check flag for existing file
    if (!file) {
        return false;
    }
    // writing data on my file: I cast the file, the size
    file.write((char *)&fileHeader, sizeof(fileHeader));
    file.write((char *)&infoHeader, sizeof(infoHeader));
    file.write((char *)m_pPixels.get(), m_width*m_height*3); // N.B. i have unique pointer
    // so I can't cast it to a char. so I have to use GET METHOD

    file.close();

    if (!file) { // to check if I really close the file
        return false;
    }

    return true;
}

// function member for the colors of each pixel
void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue){
    // adding a pointer to x,y pixel
    uint8_t *pPixel = m_pPixels.get(); // i point to all memory block
    // now I want to move to specific pixel, bit by bit

    pPixel += (y * 3) * m_width + (x * 3);//moving forward, each pixel have 3 bits of info

    //subscript array to reference the rgb bits
    pPixel[0] = blue;
    pPixel[1] = green;
    pPixel[2] = red; // n.b.: they are in the reverse order

}

// destructor
Bitmap::~Bitmap(){

}


}/* namespace caveofprogramming */
