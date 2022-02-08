#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "Dog.h"

template <typename T>
T myMin(T a, T b)
{
  return (a < b) ? a : b;
}

template <typename T1, typename T2>
void display(T1 &a, T1 &b)
{
  std::cout << a << "\n" << b << std::endl;
}

int main()
{
  std::vector<int> vec { 10, 12, 14 };

  std::cout << "Sorted:" << std::endl;
  std::sort(vec.begin(), vec.end());

  for(auto i : vec)
  {
    std::cout << i << std::endl;
  }

  std::cout << "Reversed:" << std::endl;
  std::reverse(vec.begin(), vec.end());

  for(auto i : vec)
  {
    std::cout << i << std::endl;
  }

  int sum(0);

  sum = std::accumulate(vec.begin(), vec.end(), 0);

  std::cout << "Sum of elements: " << sum << std::endl;

  int i = 2, j = 3;
  
  Dog sh("Sharo", 10, 14);
  Dog rk("Reks", 11, 7);

  std::cout << myMin(i, j) << std::endl;
  std::cout << myMin(10, 12) << std::endl;
  std::cout << myMin(13.2, 14.4) << std::endl;
  std::cout << myMin('a', 'b') << std::endl;
  std::cout << myMin<Dog>(sh, rk) << std::endl;

  display<Dog, Dog>(sh, rk);

  return 0;
}