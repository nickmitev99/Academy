#include <iostream>
#include "Dog.h"
#include "Animal.h"

int main(void)
{
  // Dog dg("Sharo", 10, 20);
  // Dog dg2(20, 40);
  // Dog dg3;

  // std::cout << "\nName: " << dg.getName() << " Height: " << dg.getHeight() << " Weight: " << dg.getWeight() << std::endl;
  // std::cout << "\nName: " << dg2.getName() << " Height: " << dg2.getHeight() << " Weight: " << dg2.getWeight() << std::endl;
  // std::cout << "\nName: " << dg3.getName() << " Height: " << dg3.getHeight() << " Weight: " << dg3.getWeight() << std::endl << std::endl;

  // Dog *dg = new Dog("Sharo", 10, 40);

  // std::cout << "\nName: " << dg->getName() << " Height: " << dg->getHeight() << " Weight: " << dg->getWeight() << std::endl;

  // delete dg;

  // Dog *dg2 = (Dog*)malloc(sizeof(Dog));

  // free(dg2);

  // std::cout << "Main: " << std::endl;
  // {
  //   std::cout << "Scope: " << std::endl; 
  //   Dog dg2;
  //   std::cout << "Exiting scope.." << std::endl;
  // }

  // std::cout << "Exiting main.." << std::endl;

  // Dog dg("Sharo", 0, 0);

  // std::cout << "\nName: " << dg.getName() << " Height: " << dg.getHeight() << " Weight: " << dg.getWeight() << std::endl;

  Dog dg("Name", 20, 30);
  Dog dg2(20, 30);
  Dog dg3("Hello");
  Dog dg4(30);
  Dog dg5("My", 20);
  Dog copy = dg5;

  std::cout << "\nName: " << copy.getName() << " Height: " << copy.getHeight() << " Weight: " << copy.getWeight() << std::endl;

  return 0;
}