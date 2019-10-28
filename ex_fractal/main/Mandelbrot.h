#ifndef MANDELBROT_H_INCLUDED
#define MANDELBROT_H_INCLUDED

namespace caveofprogramming{

// i pass some (x,y)-coordinates (-1,+1)
// and it iterates giving some coordinates
class Mandelbrot {
    public:
        static const int MAX_ITERATIONS = 1000;
        // the more the iterations, the better the quality of the index
    public:
        Mandelbrot();
        virtual ~Mandelbrot();

        static int getIterations(double x, double y);
};


}

#endif // MANDELBROT_H_INCLUDED
