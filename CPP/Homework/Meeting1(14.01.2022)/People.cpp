#include "People.h"
#include <string>

Person::Person()
{
  strEGN = "0000000000";
  iHeight = 0;
  iWeight = 0;
  strEyeCol = "Black";
  strFName = "None";
  strLName = "None";
}

Person::Person(std::string egn = { 0 }, int height = { 0 }, int weight = { 0 }, std::string eye = { 0 }, std::string fname = { 0 }, std::string lname = { 0 })
{
  strEGN = egn;
  iHeight = height;
  iWeight = weight;
  strEyeCol = eye;
  strFName = fname;
  strLName = lname;
}

Person::~Person()
{
  std::cout << "Object destroyed!" << std::endl;
}

void Person::setEGN(std::string EGN)
{
  int iEGN = EGN.length();

  if(iEGN != 10)
  {
    strEGN = "INVALID EGN";
    return;
  }

  for(int i = 0; i < iEGN; i++)
  {
    char ch = EGN[i];

    if(isalpha(ch))
    {
      strEGN = "INVALID EGN";
      return;
    }
  }

  strEGN = EGN;
}

void Person::setHeight(int Height)
{
  if(Height > 300)
  {
    iHeight = 300;
    return;
  }

  iHeight = Height;
}

void Person::setWeight(int Weight)
{
  if(Weight > 500)
  {
    iWeight = 500;
    return;
  }

  iWeight = Weight;
}

void Person::setEye(std::string Eye)
{
  if( (Eye != "Brown") || (Eye != "Black") || (Eye != "Blue") || (Eye != "Green") || (Eye != "Red") )
  {
    Eye = "Brown";
  }

  strEyeCol = Eye;
}

void Person::setFName(std::string Fname)
{
  if( (Fname[0] < 65) || (Fname[0] > 90) )
  {
    Fname[0] = toupper(Fname[0]);
  }

  strFName = Fname;
}

void Person::setLName(std::string Lname)
{
  if( (Lname[0] < 65) || (Lname[0] > 90) )
  {
    Lname[0] = toupper(Lname[0]);
  }

  strLName = Lname;
}

int Person::getHeight()
{
  return iHeight;
}

int Person::getWeight()
{
  return iWeight;
}

std::string Person::getEye()
{
  return strEyeCol;
}

std::string Person::getFName()
{
  return strFName;
}

std::string Person::getLName()
{
  return strLName;
}