#include "ClimaRemoteControl.h"
#include <iostream>

ClimaRemoteControl::ClimaRemoteControl()
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
  bStatus = 1;

  std::cout << "The AC is " << *this << std::endl;
}

void ClimaRemoteControl::Off()
{
  bStatus = 0;

  std::cout << "The AC is " << *this << std::endl;
}

void ClimaRemoteControl::Play()
{
  std::cout << "The AC is playing" << std::endl;
}
