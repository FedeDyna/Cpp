#ifndef ZOOM_H_INCLUDED
#define ZOOM_H_INCLUDED

namespace caveofprogramming{

struct Zoom{
    // public: by default
    // in line constructor
    int x{0};
    int y{0};
    double scale{0.0};
    // constructor
    Zoom(int x, int y, double scale): x(x), y(y), scale(scale) {};

};


}

#endif // ZOOM_H_INCLUDED
