#include "movingbox.h"
#include "decorator.h"
#include  <iostream>
using namespace std;

MovingBox::MovingBox(AsciiArt * thePicture, int t, int b, int l, int r, char c, char dir): 
Decorator{thePicture}, t{t}, b{b}, l{l}, r{r}, c{c}, dir{dir} {} 

char MovingBox::charAt(int row, int col, int tick) {
  if ((dir == 'u') and ((row >= t - tick) and (row <= b - tick)) and ((col >= l) and (col <= r)))  {return c;}
  if ((dir == 'd') and ((row >= t + tick) and (row <= b + tick)) and ((col >= l) and (col <= r)))  {return c;}
  if ((dir == 'r') and ((row >= t) and (row <= b)) and ((col >= l + tick) and (col <= r + tick)))  {return c;}
  if ((dir == 'l') and ((row >= t) and (row <= b)) and ((col >= l - tick) and (col <= r - tick)))  {return c;}
  return thePicture->charAt(row, col, tick);
};
