#ifndef CREATURE_H
#define CREATURE_H

#include <string>

class ICreature
{
  public:

  virtual void talk(std::string talk = "") = 0; //Pure virtual function; makes the class abstract (can't create an object)
  virtual void jump() = 0;

  virtual ~ICreature() {}
};

#endif //CREATURE_H