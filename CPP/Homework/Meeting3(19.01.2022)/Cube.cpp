#include <iostream>
#include "Cube.h"

Cube::Cube(int zZ) : z(zZ)
{
  std::cout << "\nCube constructor" << std::endl;
}

Cube::Cube(const Cube &cRef) : Square(cRef.pt) 
{
  std::cout << "\nCube copy constructor" << std::endl;
  x = cRef.x;
  y = cRef.y;
  z = cRef.z;
}

Cube::~Cube()
{
    std::cout << "\nCube destructor" << std::endl;
}