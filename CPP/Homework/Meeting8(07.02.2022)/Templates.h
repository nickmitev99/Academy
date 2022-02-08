#ifndef TEMPLATES_H
#define TEPLATES_H

#include <iostream>
#include <math.h>

template <typename T1, typename T2>
class My_Pair
{
private:
  T1 first;
  T2 second;

public:
  My_Pair(T1 f = 0, T2 s = 0) : first(f), second(s) {}

  friend std::ostream& operator<<(std::ostream &out, const My_Pair<T1, T2> &ref)
  {
  out << ref.first << " and " << ref.second << std::endl;

  return out;
  }
};

template<typename T>
T my_Sqrt(T t)
{
  return sqrt(t);
}

#endif //TEMPLATES_H