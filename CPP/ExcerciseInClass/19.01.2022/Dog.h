#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal
{
  private:
  
  int weight;
  int height;

  public:

  Dog(std::string nam = "Default", int w = 0, int h = 0); //Parametrisized and Default Constructor

  Dog(int w) : Dog() { weight = w, this->height = height; } //Delegated Constructor

  Dog(int w, int h) : Animal(), weight(w), height(h) {}  //Parametrisized Constructor

  Dog(const Dog &ref);

  ~Dog(); //Destructor

  void set_weight_height(int w, int h);
  int getWeight();
  int getHeight();
};

#endif //DOG_H