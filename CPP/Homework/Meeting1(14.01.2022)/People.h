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

  Person();
  Person(std::string egn, int height, int weight, std::string eye, std::string fname, std::string lname);
  ~Person();

  void setEGN(std::string EGN);
  void setHeight(int Height);
  void setWeight(int Weight);
  void setEye(std::string Eye);
  void setFName(std::string Fname);
  void setLName(std::string Lname);

  inline std::string getEGN() { return strEGN; }

  int getHeight();
  int getWeight();
  std::string getEye();
  std::string getFName();
  std::string getLName();
};

#endif //PEOPLE_H