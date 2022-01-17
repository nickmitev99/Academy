#include "Address.h"
#include "People.h"
#include <iostream>

int main()
{
  Person Petko;
  
  Petko.setEGN("A9903030110");
  Petko.setFName("petko");
  Petko.setLName("petkov");
  Petko.setHeight(5000);
  Petko.setWeight(1000);
  Petko.setEye("Kafqv");
  Petko.oAddress.setCity("123");
  Petko.oAddress.setCountry("Burgas");
  Petko.oAddress.setFlatNum(296);
  Petko.oAddress.setStreet("FLat Street");
  Petko.oAddress.setNumber(101);
  Petko.oAddress.setHood("Izgrev");

  std::cout << Petko.getEGN() << std::endl;
  std::cout << Petko.getFName() << std::endl;
  std::cout << Petko.getLName() << std::endl;
  std::cout << Petko.getEye() << std::endl;
  std::cout << Petko.getHeight() << std::endl;
  std::cout << Petko.getWeight() << std::endl;
  std::cout << Petko.oAddress.getCountry() << std::endl;
  std::cout << Petko.oAddress.getCity() << std::endl;
  std::cout << Petko.oAddress.getFlatNum() << std::endl;
  std::cout << Petko.oAddress.getStreet() << std::endl;
  std::cout << Petko.oAddress.getNumber() << std::endl;
  std::cout << Petko.oAddress.getHood() << std::endl;

  return 0;
}