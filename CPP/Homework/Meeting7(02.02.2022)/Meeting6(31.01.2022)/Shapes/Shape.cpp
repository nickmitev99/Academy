#include "Shape.h"

int Shape::area()
{
  std::cout << "Shape Parent class area :" << std::endl;
  return width * height;
}

void Shape::save()
{
  description = "Shape class: defines a shape";
}

void Shape::restore()
{
  std::cout << description << std::endl;
}