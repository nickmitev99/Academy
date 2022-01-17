#include <iostream>
#include <string>

std::string display(std::string str);
int display(int i);
double display(double d);

int passByPtr(int *p)
{
  *p = 4;

  std::cout << *p << std::endl;

  return *p;
}

int passByRef(int &p)
{
  p = 4;

  std::cout << p << std::endl;

  return p;
}

int main(void)
{
  int i = 10;

  passByPtr(&i);
  passByRef(i);

  return 0;
}

std::string display(std::string str)
{
  std::cout << "String: " << str << std::endl;

  return str;
}

int display(int i)
{
  std::cout << "Int: " << i << std::endl;

  return i;
}

double display(double d)
{
  std::cout << "Double: " << d << std::endl;

  return d;
}