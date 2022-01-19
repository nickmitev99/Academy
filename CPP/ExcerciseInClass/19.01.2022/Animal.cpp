#include "Animal.h"
#include <iostream>
#include <string>

Animal::Animal() : name("Gosho")
{
  std::cout << "Animal constructor" << std::endl;
}

Animal::Animal(std::string nam) : name(nam) 
{
  std::cout << "Animal constructor" << std::endl;
}

Animal::~Animal()
{
  std::cout << "Animal destructor" << std::endl;
}

void Animal::setName(std::string aName)
{
  if(aName == "Sharo")
  {
    name = "SHARO";
  }
  else
  {
    name = aName;
  }

  std::cout << name << "'s lenght is: " << name.length() << std::endl;
}

std::string Animal::getName()
{
  return name;
}

void Animal::setAge(int aYear)
{
  if(aYear > 100)
  {
    year = 25;
  }
  else
  {
    year = aYear;
  }
}

int Animal::getAge()
{
  return year;
}

void Animal::breath()
{
  std::cout << "Animal breathing." << std::endl;
}

void Animal::talk(std::string speak)
{
  std::cout << name << " says " << speak << std::endl;
}

int Animal::nextYear(int year)
{
  return ++year;
}