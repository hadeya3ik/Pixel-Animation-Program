#ifndef GRAPHOBSERVE_H
#define GRAPHOBSERVE_H

#include "observer.h"
#include "studio.h"
#include "window.h"

using namespace std;

class GraphicalObserver: public Observer {
    Studio *theStudio;
    Xwindow *window;
    int t; 
    int b; 
    int l; 
    int r; 
    public:

    // cotr, creates a graphical observer on the window
    GraphicalObserver(Studio *obj, Xwindow *window,int t, int b, int l, int r);

    // dtor, deleted the graphical observer 
    ~GraphicalObserver();

    // notify() updates the state of a graphical based observers (window) 
    void notify() override;
};

#endif
