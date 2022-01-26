#ifndef CUBE_H
#define CUBE_H

#include "Square.h"

class Cube : public Square
{
  private:
  int *z;
  static int cbCounter;

  public:
  Cube(int p = 0, int xX = 0, int yY = 0, int zZ = 0);
  Cube(const Cube &cRef);
  Cube(Cube &&rRef) noexcept; 
  ~Cube();

  inline int getZ() const { return *z; }
  
  static int getCbCount();

  void displayCube();
};

#endif //CUBE_H