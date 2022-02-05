#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include "Creature.h"
#include "Mammal.h"
#include <string>

class Animal : public ICreature, public IMammal
{
  private:

  int year;

  protected:
  std::string name;

  public:
  virtual void talk(std::string speak = "");
  virtual void jump();
  virtual void suck();

  public:
  Animal();
  Animal(std::string name);
  virtual ~Animal();

  void setName(std::string aName);
  std::string getName();

  void setAge(int aYear);
  int getAge();

  void breath();
  int nextYear(int year);
};

#endif //_ANIMAL_H_