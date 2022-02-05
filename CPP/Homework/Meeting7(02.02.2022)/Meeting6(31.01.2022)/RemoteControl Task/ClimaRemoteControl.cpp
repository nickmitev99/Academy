#include "ClimaRemoteControl.h"
#include <iostream>

ClimaRemoteControl::ClimaRemoteControl() : bStatus(false)
{
  std::cout << "Clima constructor" << std::endl;
}

ClimaRemoteControl::~ClimaRemoteControl()
{
  std::cout << "Clima destructor" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const ClimaRemoteControl& oRef)
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

void ClimaRemoteControl::On()
{
  if(bStatus == true)
  {
    throw("The AC is already on!");
  }

  bStatus = true;

  std::cout << "The AC is " << *this << std::endl;
}

void ClimaRemoteControl::Off()
{
  if(bStatus == true)
  {
    throw("The AC is already off!");
  }

  bStatus = false;

  std::cout << "The AC is " << *this << std::endl;
}

void ClimaRemoteControl::Play()
{
  std::cout << "The AC is playing" << std::endl;
}
