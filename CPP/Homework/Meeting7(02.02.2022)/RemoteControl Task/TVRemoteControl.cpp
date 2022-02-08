#include "TVRemoteControl.h"
#include <iostream>

TVRemoteControl::TVRemoteControl() : bStatus(false)
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
  if(bStatus == true)
  {
    throw("The TV is already on!");
  }

  bStatus = true;

  std::cout << "The TV is " << *this << std::endl;
}

void TVRemoteControl::Off()
{
  if(bStatus == false)
  {
    throw("The TV is already off!");
  }

  bStatus = false;

  std::cout << "The TV is " << *this << std::endl;
}

void TVRemoteControl::Play()
{
  std::cout << "The TV is playing" << std::endl;
}
