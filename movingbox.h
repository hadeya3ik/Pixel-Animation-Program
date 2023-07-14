#ifndef MOVINGBOX_H
#define MOVINGBOX_H
#include "asciiart.h"
#include "decorator.h"
#include <iostream>

class MovingBox: public Decorator {
  int t;
  int b;
  int l;
  int r; 
  char c;
  char dir; 
 public:
  MovingBox(AsciiArt *thePicture, int t, int b, int l, int r, char c, char dir);
  char charAt(int row, int col, int tick) override;
};

#endif
