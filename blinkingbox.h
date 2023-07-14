#ifndef BLINKINGBOX_H
#define BLINKINGBOX_H
#include "asciiart.h"
#include "decorator.h"

using namespace std;
class BlinkingBox: public Decorator {
  int t;
  int b;
  int l;
  int r; 
  char c;
 public:
  BlinkingBox(AsciiArt *thePicture, int t, int b, int l, int r, char c);
  char charAt(int row, int col, int tick) override;
};

#endif
