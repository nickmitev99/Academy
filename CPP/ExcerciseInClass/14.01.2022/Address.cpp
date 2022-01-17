  #include <iostream>
  #include <string>
  #include <ctype.h>
  #include "Address.h"

void Address::setCity(std::string City)
{
  int iSize = City.length();

  for(int i = 0; i < iSize; i++)
  {
    char ch = City[i];

    if(isdigit(ch))
    {
      strCity = "INVALID CITY";
      return;
    }
  }

  strCity = City;    
}

void Address::setCountry(std::string Country)
{
  if(Country == strCity)
  {
    strCountry = "c" + Country;
  }
  else
  {
    strCountry = Country;
  }
}

void Address::setStreet(std::string Street)
{
  if(Street.length() > 10)
  {
    strStreet = "National: " +  Street;
  }
  else
  {
    strStreet = Street;
  }
}

void Address::setNumber(int Number)
{
  if(Number > 100)
  {
    iNumber = Number + 1000;
  }
  else
  {
    iNumber = Number;
  }
}

void Address::setHood(std::string Hood)
{
  if(Hood == "Black")
  {
    strHood = "BLACK";
  }
  else
  {
    strHood = Hood;
  }
}

void Address::setFlatNum(int FlatNum)
{
  if(FlatNum > 9)
  {
    FlatNum += 100;
  }

  iFlatNum = FlatNum;
}

std::string Address::getCity()
{
  return strCity;
}

std::string Address::getCountry()
{
  return strCountry;
}

std::string Address::getStreet()
{
  return strStreet;
}

int Address::getNumber()
{
  return iNumber;
}

std::string Address::getHood()
{
  return strHood;
}

int Address::getFlatNum()
{
  return iFlatNum;
}