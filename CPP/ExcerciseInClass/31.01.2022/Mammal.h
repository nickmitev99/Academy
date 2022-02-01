#ifndef MAMMAL_H
#define MAMMAL_H

#include <string>

class IMammal
{
  public:

  virtual void suck() = 0;

  virtual ~IMammal() {}
};

#endif //MAMMAL_H