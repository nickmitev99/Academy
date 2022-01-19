#include <iostream>
#include "Point.h"

Point::Point(int p) : pt(p) 
{
  std::cout << "\nPoint constructor" << std::endl;
}

Point::Point(const Point &pRef) : pt(pRef.pt) 
{
  std::cout << "\nPoint copy constructor" << std::endl;
}

Point::~Point()
{
    std::cout << "\nPoint destructor" << std::endl;
}