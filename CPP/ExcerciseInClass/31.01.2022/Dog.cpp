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

void Dog::printDog()
{
  std::cout << "\nName: " << getName() << " Height: " << getHeight() << " Weight: " << getWeight() << std::endl;
}

Dog operator+(const Dog &d1, const Dog &d2)
{
  Dog d3;

  d3.weight = d1.weight + d2.weight;
  d3.height = d1.height + d2.height;

  return d3;
}

Dog operator-(const Dog &d1, const Dog &d2)
{
  Dog d3;

  d3.weight = d1.weight - d2.weight;
  d3.height = d1.height - d2.height;

  return d3;
}

Dog Dog::operator+(const Dog &d)
{
  Dog d2;

  d2.weight = weight + d.weight;
  d2.height = height + d.height;

  return d2;
}

Dog Dog::operator-(const Dog &d)
{
  Dog d2;

  d2.weight = weight - d.weight;
  d2.height = height - d.height;

  return d2;
}

Dog& Dog::operator=(const Dog &d)
{
  weight = d.weight;
  height = d.height;

  return *this;
}

Dog operator+(const Dog &d, int n)
{
  Dog newD;

  newD.height = d.height + n;
  newD.weight = d.weight + n;

  return newD;
}

Dog operator+(int n, const Dog &d)
{
  Dog newD;

  newD.height = d.height + n;
  newD.weight = d.weight + n;

  return newD;
}

Dog Dog::operator+(int n)
{
  Dog d2;

  d2.weight = weight + n;
  d2.height = height + n;

  return d2;
}

std::ostream& operator<<(std::ostream &out, const Dog &dRef)
{
  out << "Name: " << dRef.name << "\tHeight: " << dRef.height << "\tWeight: " << dRef.weight;

  return out;
}

std::istream& operator>>(std::istream &in, Dog &dRef)
{
  in >> dRef.name >> dRef.height >> dRef.weight;

  return in;
}

bool operator>(const Dog& d1, const Dog& d2)
{
  return d1.height > d2.height ? 1 : 0;
}

bool Dog::operator>(const Dog &dRef)
{
  return height > dRef.height;
}

void Dog::talk(std::string talk)
{
  std::cout <<"Dog says " << talk << std::endl;
}