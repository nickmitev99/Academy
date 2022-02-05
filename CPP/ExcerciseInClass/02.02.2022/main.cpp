#include <iostream>
#include "Dog.h"
#include "Cat.h"
#include "Animal.h"
#include "Creature.h"
#include "Exception.h"
#include <exception>

int main(void)
{
  Dog *dp = nullptr;

  try
  {
    dp = new Dog;

    dp->set_weight_height(200, 500);
  }
  catch(Exception &eRef)
  {
    std::cout << "Exc: " << eRef.what() << std::endl;
  }
  catch(GenericException &eRef)
  {
    std::cout << "Generic: " << eRef.what() << std::endl;
  }
  catch(int err)
  {
    std::cout << err << std::endl;
  }
  catch(const char *error)
  {
    std::cout << error << std::endl;
  }
  catch(...)
  {
    std::cout << "Exception is caught" << std::endl;
  }

  if(dp)
  {
    delete dp;
  }

  return 0;
}