#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:
  Rectangle(int a = 0, int b = 0) : Shape(a, b) {}

  virtual int area();
  virtual void save();
  virtual void restore();
};

#endif //RECTANGLE_H
