#include "FractalCreator.h"

namespace caveofprogramming{

FractalCreator::FractalCreator(int width, int height) : m_width(width),
    m_height(height), m_histogram(new int[Mandelbrot::MAX_ITERATIONS+1]{}),
    m_fractal(new int[m_width*m_height]{0}), m_bitmap(m_width,m_height),
    m_zoomList(m_width,m_height) {

    m_zoomList.add(Zoom(m_width/2, m_height/2, 4.0/m_width));
}

FractalCreator::~FractalCreator(){

}

void FractalCreator::calculateIteration(){

    // create a complete red bitmap
    for (int y = 0; y<m_height; y++){
        for (int x = 0; x < m_width; x++) {
            pair<double, double> coords = m_zoomList.doZoom(x,y);

            int iterations = Mandelbrot::getIterations(coords.first,coords.second);

            m_fractal[y*m_width+x] = iterations; // store the number or iterations per pixel

            if (iterations != Mandelbrot::MAX_ITERATIONS){
                m_histogram[iterations]++; // for the m_histogram color function
            }
        }
    }
}

void FractalCreator::calculateTotalIterations(){

    for (int i =0; i<Mandelbrot::MAX_ITERATIONS; i++){
        m_total += m_histogram[i];
    }
}

void FractalCreator::drawFractal(){

    // I moved the color code here, in the loop above I
    // just compute the number of iterations per pixel
    for (int y = 0; y<m_height; y++){
        for (int x = 0; x < m_width; x++) {

            uint8_t red = 0;
            uint8_t green =0;
            uint8_t blue = 0;

            // iterations for each pixels
            int iterations = m_fractal[y*m_width + x];

            if (iterations != Mandelbrot::MAX_ITERATIONS){

                double hue=0.0; // change from 0 to 1, to create the color
                for (int i = 0; i <= iterations; i++){
                    hue += ((double)m_histogram[i])/m_total;
                } // change the color proportional to the number of iterations in the pixel
                green = hue*255; // this will be smaller then 255 because 0 < hue < 1
            }
            m_bitmap.setPixel(x,y,red,green,blue);
        }
    }
}


void FractalCreator::addZoom(const Zoom& zoom){
    m_zoomList.add(zoom);
}

void FractalCreator::writeBitmap(string name){
    m_bitmap.write(name);
}

}
