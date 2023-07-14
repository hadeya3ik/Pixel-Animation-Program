#ifndef FILLEDBOX_H
#define FILLEDBOX_H
#include "decorator.h"
#include "asciiart.h"
using namespace std;

class FilledBox: public Decorator {
  int t;
  int b;
  int l;
  int r; 
  char c;
 public:
  FilledBox(AsciiArt *thePicture, int t, int b, int l, int r, char c);
  char charAt(int row, int col, int tick) override;
};

#endif
