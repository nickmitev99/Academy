#ifndef DOG_H
#define DOG_H
#include "Animal.h"
#include "People.h"

class Dog : public Animal
{
  private:
  
  int weight;
  int height;

  public:
  Person owner;
  void set_weight_height(int w, int h);
  int getWeight();
  int getHeight();
  void walking();
};

#endif //DOG_H