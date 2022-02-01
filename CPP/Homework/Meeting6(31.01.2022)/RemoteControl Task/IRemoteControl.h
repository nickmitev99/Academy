#ifndef IREMOTE_H
#define IREMOTE_H

class IRemoteControl
{
  public:
  virtual void On() = 0;
  virtual void Off() = 0;
  virtual void Play() = 0;


  public:
  
  virtual ~IRemoteControl() {}
};

#endif //IREMOTE_H