#include "blinkingbox.h"

using namespace std;

BlinkingBox::BlinkingBox(AsciiArt * thePicture, int t, int b, int l, int r, char c): 
Decorator{thePicture}, t{t}, b{b}, l{l}, r{r}, c{c} {} 

char BlinkingBox::charAt(int row, int col, int tick) {
  if (((row >= t) and (row <= b)) and ((col >= l) and (col <= r)) and (tick%2 == 0))  return c;
  return thePicture->charAt(row, col, tick);
};

