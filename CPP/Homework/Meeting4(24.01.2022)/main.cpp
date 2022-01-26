#include <iostream>
#include "Cube.h"

int main()
{
  Point pt(1);

  pt.displayPoint();
  pt.getThis();

  Point pt2 = std::move(pt);

  pt2.displayPoint();
  pt.getThis();

  Point pt3 = pt2;

  pt2.displayPoint();
  pt.getThis();

  Square s(10, 20, 30);

  s.displaySquare();
  s.getThis();

  Square s2 = std::move(s);

  s2.displaySquare();
  s2.getThis();

  Square s3 = s2;

  s3.displaySquare();
  s3.getThis();


  Cube c(0, 1, 2, 3);

  c.displayCube();
  c.getThis();

  Cube c2 = std::move(c);

  c2.displayCube();
  c2.getThis();

  Cube c3 = c2;

  c3.displayCube();
  c3.getThis();

  std::cout << std::endl;

  std::cout << "Points: " << Point::getPtCount() << std::endl;
  std::cout << "Squares: " << Square::getSrCount() << std::endl;
  std::cout << "Cubes: " << Cube::getCbCount() << std::endl;

  std::cout << std::endl;

  return 0;
}