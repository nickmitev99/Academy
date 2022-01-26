#include <iostream>
#include "Fraction.h"

// 1.Напишете клас с име Fraction, който има число и член на знаменателя. Напишете
// функция print (), която отпечатва деленето на двете числа 1:4 като 1/4.

// 2. Добавете предефинирани оператори за умножение, за да боравите с умножение
// между дроби и цяло число и между две дроби. Използвайте friend метод.

// 4. Използвайте класа Fraction, който правихме в предишния пример и
// предефинирайте операторите operator<< , operator>>

int main(void)
{
  //Task1
  Fraction f1(1, 4);
  Fraction f2(3, 6);

  std::cout << "f1 = ";
  f1.print();
  std::cout << "f2 = ";
  f2.print();

  //Task2
  Fraction f3;

  std::cout << "f3 = ";
  f3 = f1 * f2;

  f3.print();

  //Task4
  Fraction first;
  Fraction second;

  std::cout << "\nEnter the divider and denominator for the first fraction: ";
  std::cin >> first;

  std::cout << "Enter the divider and denominator for the second fraction: ";
  std::cin >> second;

  std::cout << std::endl;

  std::cout << first << " * " << second << " = " << first * second << std::endl;

  return 0;
}