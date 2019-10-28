#include <iostream>
#include "FractalCreator.h"


/* m_fractal image to a bitmap */
using namespace std;
using namespace caveofprogramming;

/*1. at top of bitmap file i need to write specidic header,
  to do that i create a struct to incorporate th header
  of the bitmap file.*/
int main()
{
    int height = 600;
    int width = 800;

    FractalCreator fractalCreator(width,height);

    fractalCreator.addZoom(Zoom(295, height-202, 0.1));
   /* fractalCreator.addZoom(Zoom(312, height-304, 0.1));
    fractalCreator.addZoom(Zoom(178, height-284, 0.01));
    fractalCreator.addZoom(Zoom(337, height-418, 0.1));*/

    fractalCreator.calculateIteration();
    fractalCreator.calculateTotalIterations();
    fractalCreator.drawFractal();

// all modifications on the m_bitmap MUST be done BEFORE this line
    fractalCreator.writeBitmap("test.bmp");

    system ("gimp test.bmp ");
    cout << "Finished!" << endl;
    return 0;
}
