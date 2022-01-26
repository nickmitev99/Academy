#include <iostream>
#include "Point.h"

int Point::ptCounter = 0;

int Point::getPtCount() 
{ 
  return ptCounter;
}

Point::Point(int p)
{
  ptCounter++;

  std::cout << "\nPoint constructor" << std::endl;

  pt = new int;

  *pt = p;
}

Point::~Point()
{
  ptCounter--;

  std::cout << "\nPoint destructor" << std::endl;
  delete pt;
}

Point::Point(const Point &pRef)
{
  pt = new int;
  *pt = *pRef.pt;

  std::cout << "\nPoint deep copy constructor" << std::endl;
}

Point::Point(Point &&rRef) noexcept : pt(rRef.pt)
{
  rRef.pt = nullptr;

  std::cout << "\nPoint move constructor" << std::endl;
}

int Point::getThis() const
{
  std::cout << "this: " << this << std::endl;

  return 0;
}

void Point::displayPoint()
{
  std::cout << __func__  << ":\nCount = " << getPtCount() << "\tpt = " << getPt() << std::endl;
}