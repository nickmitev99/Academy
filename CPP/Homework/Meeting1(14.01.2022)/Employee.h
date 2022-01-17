#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "People.h"
#include "Address.h"

class Employee : protected Person
{
  private:

  double dBalance;

  public:

  void addToBalance();
  void subtractFromBalance();
  void printBalance();
};

#endif //EMPLOYEE_H