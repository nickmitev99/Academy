#ifndef SQUARE_H
#define SQUARE_H

#include "Point.h"

class Square : public Point
{
  protected:
  int x;
  int y;

  public:
  Square(int xX = 0, int yY = 0);
  Square(const Square &sRef);
  ~Square();

  int getX() { return x; }
  int getY() { return y; }
};

#endif //SQUARE_H