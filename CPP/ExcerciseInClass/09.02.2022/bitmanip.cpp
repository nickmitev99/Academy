#include <iostream>
#include <string>
#include <iomanip>
#include <bitset>
#include <algorithm>
#include <cstdlib>

std::ostream& tab(std::ostream& out)
{
  return out << '\t';
}

std::ostream& newL(std::ostream& out)
{
  return out << '\n' << std::flush;
}


void displayBit()
{
  int num = 255, num2 = -255;
  double numd = 123456789.987654321;
  double numd2 = 1234.4321;

  std::cout << "--Bit Manipulation--" << std::endl;

  std::bitset<8> x(num);
  std::string str1 = "hello world!";
  std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);

  std::cout << std::showpos << std::endl;
  std::cout <<  num2 << std::endl;
  std::cout << std::dec << num << std::endl;
  std::cout << std::showbase << std::uppercase << std::endl;
  std::cout << std::oct << num << std::endl;
  std::cout << std::hex << num << std::endl;
  std::cout <<  x << std::endl;
  std::cout << str1 << std::endl;

  std::cout << std::resetiosflags(std::ios::showbase);
  std::cout << std::resetiosflags(std::ios::showpos);
  std::cout << std::resetiosflags(std::ios::basefield);
  std::cout << std::resetiosflags(std::ios::uppercase);

  std::cout <<  num2 << std::endl;
  std::cout << std::dec << num << std::endl;
  std::cout << std::oct << num << std::endl;
  std::cout << std::hex << num << std::endl;
  std::cout <<  x << std::endl;
  std::cout << str1 << std::endl;

  std::cout << std::setprecision(8);
  std::cout << numd << std::endl;
  std::cout << numd2 << std::endl;
  std::cout << std::setprecision(8) << std::fixed;
  std::cout << numd << std::endl;
  std::cout << numd2 << std::endl;
  std::cout << std::setprecision(4) << std::scientific << std::uppercase;
  std::cout << numd << std::endl;
  std::cout << numd2 << std::endl;
  std::cout << std::showpos << std::fixed;
  std::cout << numd << std::endl;
  std::cout << numd2 << std::endl;
  std::cout << std::setfill('*');
  std::cout << std::setw(16) << std::left << numd2 << std::endl;
  std::cout << std::setw(16) << numd << std::endl;
  std::cout << std::setw(16) << std::right << numd2 << std::endl;
  std::cout << std::setw(16) << numd << std::endl;

  std::cout << tab << str1 << newL << str1 << newL;
}