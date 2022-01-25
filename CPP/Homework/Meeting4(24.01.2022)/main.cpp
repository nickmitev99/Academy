#include <iostream>
#include "Cube.h"

int main()
{
  Point pt(1);

  displayPoint(pt);
  pt.getThis();

  Point pt2 = std::move(pt);

  displayPoint(pt2);
  pt.getThis();

  Point pt3 = pt2;

  displayPoint(pt2);
  pt.getThis();

  Square s(10, 20, 30);

  displaySquare(s);
  s.getThis();

  Square s2 = std::move(s);

  displaySquare(s2);
  s2.getThis();

  Square s3 = s2;

  displaySquare(s3);
  s3.getThis();


  Cube c(0, 1, 2, 3);

  displayCube(c);
  c.getThis();

  Cube c2 = std::move(c);

  displayCube(c2);
  c2.getThis();

  Cube c3 = c2;

  displayCube(c3);
  c3.getThis();

  std::cout << std::endl;

  displayPoint(pt3);
  displaySquare(s3);
  displayCube(c3);

  std::cout << std::endl;

  return 0;
}