#include "Dog.h"

void getRDog(Dog &pD)
{
  pD.breath();
}

void getPDog(Dog *pD)
{
  pD->getName();
}

int main()
{
  Dog Sharo;
  Sharo.owner.setFName("Kolio");

  //Sharo.weight = 10;

  Sharo.setName("Sharo");
  Sharo.setAge(12);
  Sharo.set_weight_height(90, 140);

  Sharo.breath();

  Sharo.talk("LOUGH!");

  std::cout << "Name: " << Sharo.getName() <<
  "\nAge: " << Sharo.getAge() <<
  "\nWeight: " << Sharo.getWeight() <<
  "\nHeight: " << Sharo.getHeight() << std::endl;

  std::cout << std::endl;

  Sharo.set_weight_height(200, 300);

    std::cout << "Name: " << Sharo.getName() <<
  "\nAge: " << Sharo.getAge() <<
  "\nWeight: " << Sharo.getWeight() <<
  "\nHeight: " << Sharo.getHeight() << std::endl;

  std::cout << std::endl;

  Sharo.walking();
  
  return 0;
}