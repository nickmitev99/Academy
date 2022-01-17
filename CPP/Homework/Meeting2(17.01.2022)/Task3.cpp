#include <iostream>

void swap(int& iVal1, int& iVal2);

int main(void)
{
  int iA = 1, iB = 2;

  std::cout << "Before swap: " << std::endl;
  std::cout << "A: " << iA << "\nB: " << iB << std::endl;

  swap(iA, iB);

  std::cout << "After swap: " << std::endl;
  std::cout << "A: " << iA << "\nB: " << iB << std::endl;

  return 0;
}

void swap(int& iVal1, int& iVal2)
{
  int iTemp = iVal1;
  iVal1 = iVal2;
  iVal2 = iTemp;
}