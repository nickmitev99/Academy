#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"

int main(void)
{
  Shape *sh = new Shape;
  Triangle *t = new Triangle;
  Rectangle *r = new Rectangle;
  int i = 0;

  //Task1

  draw(sh, 2, 3);
  draw(t, 4, 5);
  draw(r, 10, 20);

  std::cout << "Shape: " << sh->area() << std::endl;
  std::cout << "Triangle: " << t->area() << std::endl;
  std::cout << "Rectangle: " << r->area() << std::endl;

  //Task2
  reSize(*sh, 10, 10);
  reSize(*t, 20, 20);
  reSize(*r, 30, 30);

  std::cout << "Shape: " << sh->area() << std::endl;
  std::cout << "Triangle: " << t->area() << std::endl;
  std::cout << "Rectangle: " << r->area() << std::endl;

  //Task3

  sh->save();
  t->save();
  r->save();

  sh->restore();
  t->restore();
  r->restore();

  delete sh;
  delete t;
  delete r;

  return 0;
}

void draw(Shape *pSh, int w, int h)
{
  try
  {
    if(typeid(pSh) != typeid(Shape*))
    {
      throw("Incorrect type");
    }
  }
  catch(const char *msg)
  {
    std::cerr << msg << std::endl;
  }
  
  pSh->width = w;
  pSh->height = h;
}

void reSize(Shape &pSh, int w, int h)
{
  pSh.width = w;
  pSh.height = h;
}