#include "Rectangle.h"

int Rectangle::area()
{
  std::cout << "Rectangle class area :" << std::endl;
  return (width * height);
}

void Rectangle::save()
{
  description = "Rectangle class, derived from shape, connected by four lines";
}

void Rectangle::restore()
{
  std::cout << description << std::endl;
}