#include "IRemoteControl.h"
#include "TVRemoteControl.h"
#include "ClimaRemoteControl.h"
#include <iostream>

int main(void)
{
  TVRemoteControl tv;

  tv.On();
  tv.Off();
  tv.Play();

  ClimaRemoteControl cl;

  cl.On();
  cl.Off();
  cl.Play();

  return 0;
}