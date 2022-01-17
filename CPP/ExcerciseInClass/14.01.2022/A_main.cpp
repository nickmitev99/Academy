#include "Animal.h"
#include <iostream>
#include <string>

int main()
{
  //Static

  // Animal sharo;

  // sharo.name = "Sharo";
  // sharo.year = 1;

  // std::cout << sharo.name << " is " << sharo.year << " years old." << std::endl;

  // sharo.breath();

  // std::cout << "Next year " << sharo.nextYear(sharo.year) << std::endl;
  // std::cout << "obj.year = " << sharo.year << "\n" << std::endl;

  //Dynamic

  // Animal *milka;

  // milka = new Animal;

  // (*milka).name = "Milka";
  // milka->year = 10;

  // milka->talk("Muuu!");

  // std::cout << milka->name << " is " << milka->year << " years old." << std::endl;

  // delete milka;

  Animal sharo;

  std::cout << sharo.getName() << " is " << sharo.getAge() << " years old." << std::endl;

  return 0;
}