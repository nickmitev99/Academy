#include "TVRemoteControl.h"
#include <iostream>

TVRemoteControl::TVRemoteControl()
{
  std::cout << "TV constructor" << std::endl;
}

TVRemoteControl::~TVRemoteControl()
{
  std::cout << "TV destructor" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const TVRemoteControl& oRef)
{
  if(oRef.bStatus == true)
  {
    out << "ON";
  }
  else
  {
    out << "OFF";
  }

  return out;
}

void TVRemoteControl::On()
{
  bStatus = 1;

  std::cout << "The TV is " << *this << std::endl;
}

void TVRemoteControl::Off()
{
  bStatus = 0;

  std::cout << "The TV is " << *this << std::endl;
}

void TVRemoteControl::Play()
{
  std::cout << "The TV is playing" << std::endl;
}
