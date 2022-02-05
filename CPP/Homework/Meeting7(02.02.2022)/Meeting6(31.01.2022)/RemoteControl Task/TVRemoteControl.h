#ifndef TV_H
#define TV_H

#include "IRemoteControl.h"
#include <iostream>

class TVRemoteControl : public IRemoteControl
{
  private:
  bool bStatus;

  public:
  TVRemoteControl();
  virtual ~TVRemoteControl();

  public:
  friend std::ostream& operator<<(std::ostream& out, const TVRemoteControl& oRef);

  virtual void On();
  virtual void Off();
  virtual void Play();
};

#endif //TV_H