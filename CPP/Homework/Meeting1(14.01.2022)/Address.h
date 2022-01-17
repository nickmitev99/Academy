#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address
{
  private:

  std::string strCity;
  std::string strCountry;
  std::string strStreet;
  int iNumber;
  std::string strHood;
  int iFlatNum;

  public:

  void setCity(std::string City);
  void setCountry(std::string Country);
  void setStreet(std::string Street);
  void setNumber(int Number);
  void setHood(std::string Hood);
  void setFlatNum(int FlatNum);

  std::string getCity();
  std::string getCountry();
  std::string getStreet();
  int getNumber();
  std::string getHood();
  int getFlatNum();
};


#endif //ADDRESS_H