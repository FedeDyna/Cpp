#ifndef FRACTALCREATOR_H_INCLUDED
#define FRACTALCREATOR_H_INCLUDED

#include <cstdint>
#include <memory> // to create an unique pointer for the color m_histogram
#include <math.h> // for math
#include <string>
#include "Zoom.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"


using namespace std;
// this class has been written to keep
// the main as clean as possible
namespace caveofprogramming{

class FractalCreator {
    private:
        int m_width;
        int m_height;
        int m_total{0};
        // the unique pointer I use to store the number of pixels with a specific number of iterations
        unique_ptr<int[]> m_histogram;
        // to store the number of iterations per coordinate
        unique_ptr<int[]> m_fractal;
        /*create a bitmap file*/
        Bitmap m_bitmap; //width,height,color
        // create the first zoom
        ZoomList m_zoomList;


    public:
        FractalCreator(int width, int height);
        virtual ~FractalCreator();

        void calculateIteration(); // first nested
        void calculateTotalIterations();
        void drawFractal(); // second nested loop
        void addZoom(const Zoom& zoom); // passing a reference
        void writeBitmap(string name);
};

}

#endif // FRACTALCREATOR_H_INCLUDED
