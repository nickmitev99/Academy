#include "Cat.h"
#include <iostream>

void Cat::jump()
{
  std::cout <<"Cat jumped" << std::endl;
}

Cat::Cat() : Animal()
{
  std::cout << "Cat constructor" << std::endl;
}

Cat::~Cat()
{
  std::cout << "Cat destructor" << std::endl;
}