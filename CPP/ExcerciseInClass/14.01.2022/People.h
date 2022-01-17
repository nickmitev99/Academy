#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include "Address.h"

class Person
{
  private:

  std::string strEGN;
  int iHeight;
  int iWeight;
  std::string strEyeCol;
  std::string strFName;
  std::string strLName;
  
  public:
  Address oAddress;

  void setEGN(std::string EGN);
  void setHeight(int Height);
  void setWeight(int Weight);
  void setEye(std::string Eye);
  void setFName(std::string Fname);
  void setLName(std::string Lname);

  std::string getEGN();
  int getHeight();
  int getWeight();
  std::string getEye();
  std::string getFName();
  std::string getLName();
};

#endif //PEOPLE_H