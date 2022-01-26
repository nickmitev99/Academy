#include "Fraction.h"
#include <iostream>

//Constructor
Fraction::Fraction(int div, int den)
{
  //if the denominator or divider (or botr) are 0, than their values become 1
  if( (den == 0) || (div == 0) )
  {
    std::cout << "You can't enter a '0' for the divider and denominator. Setting both to 1" << std::endl;
    den = 1;
    div = 1;
  }
  else if( (den < 0) && (div < 0) )
  {
    den *= -1;
  }
  else if(den < 0)
  {
    den *= -1;
    div *= -1;
  }

  divider = div;
  denominator = den;
}

//Copy constructor
Fraction::Fraction(const Fraction &fRef)
{
  divider = fRef.divider;
  denominator = fRef.denominator;
}

//Destructor
Fraction::~Fraction()
{
  
}

//Operator =
Fraction& Fraction::operator=(const Fraction &fRef)
{
  divider = fRef.divider;
  denominator = fRef.denominator;

  return *this;
}

//Task1
void Fraction::print()
{
  std::cout << divider << "/" << denominator << std::endl;
}

//Task2
Fraction Fraction::operator*(const Fraction &fRef)
{
  Fraction f;

  f.divider = divider * fRef.divider;
  f.denominator = denominator * fRef.denominator;

  return f;
}

//Task4
std::ostream& operator<<(std::ostream &out, const Fraction& fRef)
{
  out << fRef.divider << "/" << fRef.denominator;

  return out;
}

std::istream& operator>>(std::istream &in, Fraction& fRef)
{
  in >> fRef.divider >> fRef.denominator;

  return in;
}