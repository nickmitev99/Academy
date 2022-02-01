#ifndef Clima_H
#define Clima_H

#include "IRemoteControl.h"
#include <iostream>

class ClimaRemoteControl : public IRemoteControl
{
  private:
  bool bStatus;

  public:
  ClimaRemoteControl();
  virtual ~ClimaRemoteControl();

  public:
  friend std::ostream& operator<<(std::ostream& out, const ClimaRemoteControl& oRef);

  virtual void On();
  virtual void Off();
  virtual void Play();
};

#endif // Clima_H