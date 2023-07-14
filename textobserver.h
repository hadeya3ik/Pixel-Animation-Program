#ifndef TEXTOBSERVE_H
#define TEXTOBSERVE_H

#include "observer.h"
using namespace std;

class Studio;

class TextObserver: public Observer {
    Studio *theStudio; 
    int t;
    int b;
    int l;
    int r;
    public:

    // cotr, this creates an observer for a text object
    TextObserver(Studio *theStudio, int t, int b, int l, int r);

    // dtor, deleted the observer 
    ~TextObserver() override;

    // notify() updates the state of the text base observers. 
    void notify() override;
};

#endif
