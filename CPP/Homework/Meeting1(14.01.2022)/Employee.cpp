#include <iostream>
#include "Employee.h"

void Employee::addToBalance()
{
  double dAdd = 0;

  std::cout << "Enter the amount you would like to add: ";
  std::cin >> dAdd;

  dBalance += dAdd;
}

void Employee::subtractFromBalance()
{
  double dSub = 0;

  std::cout << "Enter the amount you would like to withdraw: ";
  std::cin >> dSub;

  if(dSub > dBalance)
  {
    std::cout << "Insufficient amount in your account! Cannot withdraw " 
    << dSub << " BGN when you have " << dBalance << " BGN!" << std::endl;
    
    return;
  }

  dBalance -= dSub;
}

void Employee::printBalance()
{
  std::cout << "Current balance: " << dBalance << " BGN" << std::endl;
}
