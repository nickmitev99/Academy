//3. В горния пример на Cents, предефинирайте оператори < и <=.

#include <iostream>
#include "Cents.h"

int main(void)
{
  Cents c1(3);
  Cents c2(4);  

  if(c1 < c2)
  {
    std::cout << "This is printed because of the operator '<'" << std::endl;
  }

  Cents c3(3);

  if(c1 <= c3)
  {
    std::cout << "This is printed because of the operator '<='" << std::endl;
  }

  return 0;
}