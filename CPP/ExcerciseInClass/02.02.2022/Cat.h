#ifndef CAT_H
#define CAT_H

#include "Animal.h"
#include <string>

class Cat : public Animal
{
  
  public:
  Cat();
  virtual ~Cat();
  void jump();
};

#endif //CAT_H