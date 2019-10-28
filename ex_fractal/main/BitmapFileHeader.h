#ifndef BITMAPFILEHEADER_H_INCLUDED
#define BITMAPFILEHEADER_H_INCLUDED

// point 1. in main. The members of
// a struct are public by default, so
// in terms of efficiency, if i want
// to access members, its better to
// use struct rather then class.

#include <cstdint> // standard int librarary
using namespace std;

// padding the data following struct, othrwise bitmap is not readeable
#pragma pack(2) // pre-processor directive, no `;`
                // and it tell us how to allign the data
                // in this case, using 2-byte allignement defined in the struct BitmapFileHeader

//to call them from main, easilty?????????
namespace caveofprogramming{

struct BitmapFileHeader {
    //2 bytes with letters, a 2-element array
    char header[2]{'B','M'}; //because c++11 so i can initialize it immediatly
    // size of final file
    int32_t fileSize; // must be 4-byte precisly, 32bit but depending on architecture int can store different values (64bit for instance)
                     // to be sure of it, I will include c-standard-int library and related namespace
    int32_t reserved{0};
    int32_t dataOffset; // how long into the file the data begins
};
// N.B. cpp will aligned the data in a default way
// thus I have to avoid it, telling the compiler
// that I want to allign the data as I want, following the struc
// I created

}

#endif // BITMAPFILEHEADER_H_INCLUDED
