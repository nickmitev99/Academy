#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape
{
protected:
  int width, height;
  std::string description;

public:
  Shape(int a = 0, int b = 0)
      : width(a),
        height(b) {}

  virtual int area();
  virtual void save();
  virtual void restore();

  friend void draw(Shape *pSh, int w, int h);
  friend void reSize(Shape &pSh, int w, int h);
};

#endif //SHAPE_H