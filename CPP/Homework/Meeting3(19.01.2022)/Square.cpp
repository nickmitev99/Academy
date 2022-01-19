#include <iostream>
#include "Square.h"

Square::Square(int xX, int yY) : Point(), x(xX), y(yY)
{
  std::cout << "\nSquare constructor" << std::endl;
}

Square::Square(const Square &sRef) : Point(sRef.pt) 
{
  std::cout << "\nSquare copy constructor" << std::endl;
  x = sRef.x;
  y = sRef.y;
}

Square::~Square()
{
    std::cout << "\nSquare destructor" << std::endl;
}