#ifndef DECORATOR_H
#define DECORATOR_H
#include "asciiart.h"
using namespace std;

class Decorator: public AsciiArt {
 protected:
  AsciiArt *thePicture;
 public:
  Decorator(AsciiArt *thePicture);
  virtual char charAt(int row, int col, int tick) = 0; 
  virtual ~Decorator();
};

#endif
