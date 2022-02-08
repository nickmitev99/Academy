#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
public:
  Triangle(int a = 0, int b = 0) : Shape(a, b) {}

  virtual int area();
  virtual void save();
  virtual void restore();
};

#endif //TRIANGLE_H