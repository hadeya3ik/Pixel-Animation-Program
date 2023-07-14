#include "decorator.h"
using namespace std;
Decorator::Decorator(AsciiArt *thePicture): thePicture{thePicture} {}

Decorator::~Decorator() { delete thePicture; }
