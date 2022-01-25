#include <iostream>
#include "Point.h"

int Point::ptCounter = 0;

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

const int Point::getThis()
{
  std::cout << "this: " << this << std::endl;

  return 0;
}

void displayPoint(Point &p)
{
  std::cout << __func__  << ":\nCount = " << p.getPtCount() << "\tpt = " << p.getPt() << std::endl;
}