#ifndef SQUARE_H
#define SQUARE_H

#include "Point.h"

class Square : public Point
{
  protected:
  int *x;
  int *y;
  static int srCounter;

  public:
  Square(int p = 0, int xX = 0, int yY = 0);
  Square(const Square &sRef);
  Square(Square &&rRef) noexcept;
  ~Square();

  inline int getX() { return *x; }
  inline int getY() { return *y; }
  inline int getSrCount() { return srCounter; }
  const int displayThis();
};

void displaySquare(Square &s);

#endif //SQUARE_H