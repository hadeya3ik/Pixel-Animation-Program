#include "textobserver.h"
#include "studio.h"
#include <iostream>

using namespace std;

TextObserver::TextObserver(Studio *theStudio, int t, int b, int l, int r): theStudio{theStudio}, t{t}, b{b},l{l}, r{r} {
    theStudio->attach(this); // attaches a new observer to the vector
}

TextObserver::~TextObserver() {
    theStudio->detach(this); // removes the observes from the vector
}

void TextObserver::notify() {
    int rows = abs(l - r + 1);  // the boundaries of the row for the canvas
    int cols = abs(b - t + 1);  // the boundaries of the column for the canvas
    cout << '+';
    for (int j = 0; j < cols; ++j) cout << '-';
    cout << '+' << endl;
    for (int i = 0; i < rows; ++i) {
        cout << '|';
        for (int j = 0; j < cols; ++j) {
            cout << theStudio->getState(i + t, j + r);
        }
        cout << '|' << endl;
    }
    cout << '+';
    for (int j = 0; j < cols; ++j) cout << '-';
    cout << '+' << std::endl;
}
