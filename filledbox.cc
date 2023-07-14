#include "filledbox.h"
//#include "decorator.h"
using namespace std;

FilledBox::FilledBox(AsciiArt * thePicture, int t, int b, int l, int r, char c): 
Decorator{thePicture}, t{t}, b{b}, l{l}, r{r}, c{c} {} 

char FilledBox::charAt(int row, int col, int tick) {
  if (((row >= t) and (row <= b)) and ((col >= l) and (col <= r)))  return c;
  return thePicture->charAt(row, col, tick);
};
