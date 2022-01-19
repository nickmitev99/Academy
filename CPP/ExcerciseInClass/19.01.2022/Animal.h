#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <string>

class Animal
{
  private:

  int year;

  protected:
  std::string name;

  public:

  Animal();
  Animal(std::string name);
  ~Animal();

  void setName(std::string aName);
  std::string getName();

  void setAge(int aYear);
  int getAge();

  void breath();
  void talk(std::string speak);
  int nextYear(int year);
};

#endif //_ANIMAL_H_