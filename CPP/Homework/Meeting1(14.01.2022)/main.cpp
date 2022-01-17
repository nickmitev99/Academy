#include <iostream>
#include "Employee.h"

int main(void)
{
  // Employee Pesho;

  // Pesho.addToBalance();

  // Pesho.printBalance();

  // Pesho.subtractFromBalance();

  // Pesho.printBalance();

  Person Petko("000000000", 180, 100, "Black", "Petko", "Petkov");

  std::cout << "EGN: " << Petko.getEGN() << std::endl;
  std::cout << "First name: " << Petko.getFName() << std::endl;
  std::cout << "Last name: " << Petko.getLName() << std::endl;
  std::cout << "Eye color: " << Petko.getEye() << std::endl;
  std::cout << "Height: " << Petko.getHeight() << std::endl;
  std::cout << "Weight: " << Petko.getWeight() << std::endl;

  Employee e;

  return 0;
}