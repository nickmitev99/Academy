#include <iostream>
#include "Dog.h"
#include "Cat.h"
#include "Animal.h"
#include "Creature.h"

int main(void)
{
  // Dog d1;
  // Cat c1;
  // Animal *ptr;

  // std::cout << std::endl;

  // ptr = &d1;
  // ptr->talk(); //Calls talk from Dog
  // ptr->jump(); //Calls jump from Animal

  // std::cout << std::endl;

  // ptr = &c1;
  // ptr->talk(); //Calls talk from Animal
  // ptr->jump(); //Calls jump from Cat

  // std::cout << std::endl;

  // Animal *ptr = new Dog;

  // Dog *dP = dynamic_cast <Dog*> (ptr);

  // ptr->talk();
  // ptr->jump();
  // ptr->suck();

  // dP->set_weight_height(20, 30);

  // std::cout << *dP << std::endl;

  // Dog *dP2 = reinterpret_cast <Dog*> (ptr);

  // std::cout << *dP2 << std::endl;

  // delete ptr;

  double d = 10.6;

  int n = static_cast <int> (d);

  std::cout << n << std::endl; 

  return 0;
}