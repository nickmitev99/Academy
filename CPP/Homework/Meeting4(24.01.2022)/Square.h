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

  inline int getX() const { return *x; }
  inline int getY() const { return *y; }

  static int getSrCount();

  void displaySquare();
};

#endif //SQUARE_H