#include "maskbox.h"
#include <iostream>

MaskBox::MaskBox(AsciiArt * thePicture, int t, int b, int l, int r, char c): 
Decorator{thePicture}, t{t}, b{b}, l{l}, r{r}, c{c} {} 

char MaskBox::charAt(int row, int col, int tick) {
  if ( (((row >= t) and (row <= b)) and ((col >= l) and (col <= r))) and (thePicture->charAt(row, col, tick) != ' ')) {
    return c; 
  } else {
    return thePicture->charAt(row, col, tick); 
  }
};
