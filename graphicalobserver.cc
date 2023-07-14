#include "graphicalobserver.h"
#include "studio.h"
#include <iostream>
#include "window.h"
using namespace std;

GraphicalObserver::GraphicalObserver(Studio *obj, Xwindow *window,int t, int b, int l, int r):
  theStudio{obj}, window{window}, t{t}, b{b}, l{l}, r{r}{
    obj->attach(this); // adds the observes to the vector
}

GraphicalObserver::~GraphicalObserver(){
    theStudio->detach(this); // removes the observes from the vector
}

void GraphicalObserver::notify() {
    int colour;

    for (int i = t; i <= b; ++i) {
        for (int j = l; j <= r; ++j) { 
            // determining the char
            char c = theStudio->getState(i, j);

            // determining the colour
            colour = (c >= 'a' && c <= 'z') ? window->Red: (c >= 'A' && c <= 'Z') ? window->Green :
            (c >= '0' && c <= '9') ? window->Blue: (c == ' ') ? window->White : window->Black;

            // displaying the pixel
            window->fillRectangle(abs((j - l) * 10), abs((i - t) * 10), 10, 10, colour);
        }
    } 
}
