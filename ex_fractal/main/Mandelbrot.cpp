#include "Mandelbrot.h"
#include <complex> // for complex numbers

using namespace std;

namespace caveofprogramming{

Mandelbrot::Mandelbrot(){

}

Mandelbrot::~Mandelbrot(){}


int Mandelbrot::getIterations(double x, double y){
    // this is a template, and I create a single-value complex number
    complex<double> z = 0;
    complex<double> c(x,y); // constructor to initialize the value of c and it depends on the x,y coordinates

    int iterations = 0;

    while (iterations < MAX_ITERATIONS){
        z = z*z*z + c; // Mandelbrot algorithm
        if (abs(z) > 2) break; // Mandelbrot set

        iterations++;
    }

    return iterations;
}




}


