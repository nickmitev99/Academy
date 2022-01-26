#include <iostream>
#include "Cube.h"

int Cube::cbCounter = 0;

int Cube::getCbCount()
{ 
  return cbCounter;
}

Cube::Cube(int p, int xX, int yY, int zZ) : Square(p, xX, yY)
{
  cbCounter++;

  std::cout << "Cube constructor" << std::endl;

  z = new int;
  *z = zZ;
}

Cube::~Cube()
{
  cbCounter--;

  std::cout << "Cube destructor" << std::endl;

  delete z;
}

Cube::Cube(const Cube &cRef)
{
  z = new int;

  std::cout << "Cube copy constructor" << std::endl;

  *pt = *cRef.pt;
  *x = *cRef.x;
  *y = *cRef.y;
  *z = *cRef.z;
}

Cube::Cube(Cube &&rRef) noexcept : z(rRef.z)
{
  pt = rRef.pt;
  x = rRef.x;
  y = rRef.y;

  rRef.pt = nullptr;
  rRef.x = nullptr;
  rRef.y = nullptr;
  rRef.z = nullptr;

  std::cout << "Cube move constructor" << std::endl;
}

void Cube::displayCube()
{
  std::cout << __func__  << ":\nCount = " << getCbCount() << "\tpt = " << getPt() << "\tx = " << getX()
   << "\ty = " << getY() << "\tz = " << getZ() << std::endl;
}