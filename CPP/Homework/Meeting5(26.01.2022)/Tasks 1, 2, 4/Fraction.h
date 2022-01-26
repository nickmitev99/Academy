#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction
{
private:
  int divider;
  int denominator;
public:
  Fraction(int div = 1, int den = 1);
  Fraction(const Fraction &fRef);
  ~Fraction();

  Fraction operator*(const Fraction &fRef);

  Fraction& operator=(const Fraction &fRef);

  friend std::ostream& operator<<(std::ostream &out, const Fraction& fRef);
  friend std::istream& operator>>(std::istream &in, Fraction& fRef);

  void print();
};

#endif //FRACTION_H