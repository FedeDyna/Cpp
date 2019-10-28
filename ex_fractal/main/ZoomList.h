#ifndef ZOOMLIST_H_INCLUDED
#define ZOOMLIST_H_INCLUDED

#include <vector>
#include <utility> // to return a pair value
#include "Zoom.h"

using namespace std;

namespace caveofprogramming{

class ZoomList {
    private:
        double m_xCenter{0};
        double m_yCenter{0};
        double m_scale{1.0}; // default scale

        int m_width{0};
        int m_height{0};
        vector<Zoom> zooms;

    public:
        ZoomList(int width, int height);
        void add(const Zoom& zoom);
        // template class
        pair<double, double> doZoom(int x, int y);

};

}


#endif // ZOOMLIST_H_INCLUDED
