#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal
{
private:  
  int *iPtr;
  int weight;
  int height;

public:
  Dog(std::string nam = "Default", int w = 0, int h = 0); //Parametrisized and Default Constructor

  Dog(int w) : Dog() { weight = w, this->height = height; } //Delegated Constructor

  Dog(int w, int h) : Animal(), weight(w), height(h) {}  //Parametrisized Constructor

  Dog(const Dog &ref);

  virtual ~Dog(); //Destructor

  void set_weight_height(int w, int h);
  int getWeight();
  int getHeight();

  void printDog();

  friend Dog operator+(const Dog &d, int n);
  friend Dog operator+(int n, const Dog &d);

  friend Dog operator+(const Dog &d1, const Dog &d2);
  friend Dog operator-(const Dog &d1, const Dog &d2);

  Dog operator+(const Dog &d);
  Dog operator-(const Dog &d);

  //can be only integrated in class, can not be a friend function
  Dog& operator=(const Dog &d);

  Dog operator+(int n);

  bool operator>(const Dog &dRef);

  friend std::ostream& operator<<(std::ostream &out, const Dog &dRef);
  friend std::istream& operator>>(std::istream &in, Dog &dRef);

  friend bool operator>(const Dog& d1, const Dog& d2);

  void talk(std::string talk = "");
  // =, (), [], -> can not be friend funcs
};

#endif //DOG_H