#include <iostream>
#include "asciiart.h"
#include "blank.h"
#include "studio.h"
#include "maskbox.h"
#include "filledbox.h"
#include "blinkingbox.h"
#include "movingbox.h"
#include "textobserver.h"
#include "graphicalobserver.h"
#include <vector>
#include <memory>
#include "window.h"

int main () {
  AsciiArt *canvas = new Blank;
  vector<Observer*> observers; 
  Studio s{canvas};

  std::string command;

  while (std::cin >> command) {
    if (command == "render" ) {
      s.render();
    }
    else if (command == "animate") {
      int n;
      std::cin >> n;
      s.animate(n);
    }
    else if (command == "reset") {
      s.reset();
    }
    else if (command == "filledbox") {
      int top, bottom, left, right;
      char what;
      std::cin >> top >> bottom >> left >> right >> what;
      canvas = new FilledBox(canvas , top, bottom, left, right, what);
      s.picture() = canvas;
    }
    else if (command == "blinkingbox") {
      int top, bottom, left, right;
      char what;
      std::cin >> top >> bottom >> left >> right >> what;
      canvas = new BlinkingBox(canvas , top, bottom, left, right, what);
      s.picture() = canvas;
    }
    else if (command == "movingbox") {
      int top, bottom, left, right;
      char what, dir;
      std::cin >> top >> bottom >> left >> right >> what >> dir;
      canvas = new MovingBox(canvas, top, bottom, left, right, what, dir);
      s.picture() = canvas;
    }
    else if (command == "maskbox") {
      int top, bottom, left, right;
      char what;
      std::cin >> top >> bottom >> left >> right >> what;
      canvas = new MaskBox(canvas, top, bottom, left, right, what);
      s.picture() = canvas;
    }
    else if (command == "addtext") {
      int top, bottom, left, right;
      std::cin >> top >> bottom >> left >> right;
      TextObserver *ob = new TextObserver(&s, top, bottom, right, left);
      observers.push_back(ob);
    }
    else if (command == "addgraphics") {
      int top, bottom, left, right;
      std::cin >> top >> bottom >> left >> right;
      Xwindow *window = new Xwindow((abs(bottom - top) + 1) * 10 , (abs(left - right) + 1) * 10);
      GraphicalObserver *ob = new GraphicalObserver(&s, window, top, bottom, left, right);
      observers.push_back(ob);
    }
  }
  
  int x = observers.size();
  for (int i = 0; i < x; i++) {
    delete observers[i]; 
  }

  observers.clear();
}
