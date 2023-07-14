#ifndef MASKBOX_H
#define MASKBOX_H
#include "asciiart.h"
#include "decorator.h"

class MaskBox: public Decorator {
  int t;
  int b;
  int l;
  int r; 
  char c;
 public:
  MaskBox(AsciiArt *thePicture, int t, int b, int l, int r, char c);
  char charAt(int row, int col, int tick) override;
};

#endif
