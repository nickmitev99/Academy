#include "Triangle.h"

int Triangle::area()
{
  std::cout << "Triangle class area :" << std::endl;
  return (width * height / 2);
}

void Triangle::save()
{
  description = "Triangle class, derived from shape, connected by three lines";
}

void Triangle::restore()
{
  std::cout << description << std::endl;
}