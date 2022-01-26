#include <iostream>
#include "Dog.h"
#include "Animal.h"

int main(void)
{
  Dog d1("Sharo", 3, 3);
  Dog d2("Kolio", 2, 2);

  if(d1 > d2)
  {
    std::cout << "Hello" << std::endl;
  }

  return 0;
}