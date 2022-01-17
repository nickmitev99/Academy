#include "Dog.h"

void Dog::set_weight_height(int w, int h)
{
  if(w > 100 || h > 150)
  {
    weight = -1;
    height = -1;
  }
  else
  {
    weight = w;
    height = h;
  }
}

int Dog::getWeight()
{
  return weight;
}

int Dog::getHeight()
{
  return height;
}

void Dog::walking()
{
  std::cout << owner.getFName() << " is walking the dog " << getName() << std::endl;
}