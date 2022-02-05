#include "IRemoteControl.h"
#include "TVRemoteControl.h"
#include "ClimaRemoteControl.h"
#include <iostream>

int main(void)
{    
  TVRemoteControl tv;
  ClimaRemoteControl cl;

  try
  {
    tv.On();
    tv.Off();
    // tv.Off();                          - Trigger the TV Exception
    tv.Play();

    cl.On();
    // cl.On();                           - Trigger the AC Exception
    cl.Off();
    cl.Play();
  }
  catch(const char *msg)
  {
    std::cout << msg << std::endl;
  }

  return 0;
}