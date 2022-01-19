#ifndef CUBE_H
#define CUBE_H

#include "Square.h"

class Cube : public Square
{
  private:
  int z;

  public:
  Cube(int zZ = 0);
  Cube(const Cube &cRef); 
  ~Cube();

  int getZ() { return z; }
};

#endif //CUBE_H