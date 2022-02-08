// 1. Направете структура My_Pair с два темплейтни аргумента. В int main()
// направете няколко обекта от този структура като подадете различни типове
// std::string, int, double, char, float. 

// 2. Напишете темплейтна функция my_Sqrt(T t), която връща корен
// квадратен от стойността, подадена като параметър.

#include "Templates.h"
#include <iostream>

int main(void)
{
  My_Pair <int, float> mp(3, 4.2);
  My_Pair <std::string, char> mp2("Hello", 't');
  My_Pair <double, float> mp3(7.932, 4.2);

  std::cout << mp << std::endl;
  std::cout << mp2 << std::endl;
  std::cout << mp3 << std::endl;

  std::cout << my_Sqrt(10) << std::endl;
  std::cout << my_Sqrt(12.4) << std::endl;

  return 0;
}