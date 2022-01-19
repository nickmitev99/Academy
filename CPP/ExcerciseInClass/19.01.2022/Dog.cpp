#include "Dog.h"
#include <iostream>

Dog::Dog(std::string nam, int w, int h) : Animal(nam), weight(w), height(h) 
{
  std::cout << "Dog constructor" << std::endl;
}

Dog::Dog(const Dog &ref) : Animal(ref.name), weight(ref.weight), height(ref.height) 
{ 
  std::cout << "Copy constructor" << std::endl;
}

Dog::~Dog()
{
  std::cout << "Dog destructor" << std::endl;
}

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