#include <iostream>
#include "Square.h"

int Square::srCounter = 0;

int Square::getSrCount() 
{ 
  return srCounter; 
}

Square::Square(int p, int xX, int yY) : Point(p)
{
  srCounter++;

  x = new int;
  y = new int;

  *x = xX;
  *y = yY;

  std::cout << "Square constructor" << std::endl;
}

Square::~Square()
{
  srCounter--;

  std::cout << "Square destructor" << std::endl;

  delete x;
  delete y;
}

Square::Square(const Square &sRef)
{
  x = new int;
  y = new int;

  std::cout << "Square deep copy constructor" << std::endl;

  *pt = *sRef.pt;
  *x = *sRef.x;
  *y = *sRef.y;
}

Square::Square(Square &&rRef) noexcept : x(rRef.x), y(rRef.y)
{
  pt = rRef.pt;

  rRef.pt = nullptr;
  rRef.x = nullptr;
  rRef.y = nullptr;

  std::cout << "Square move constructor" << std::endl;
}

void Square::displaySquare()
{
  std::cout << __func__  << ":\nCount = " << getSrCount() << "\tpt = " << getPt() << "\tx = " << getX() << "\ty = " << getY() << std::endl;
}
