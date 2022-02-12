#include <iostream>
#include <ios>
#include <fstream>
#include <string>
#include <vector>

// 2. Напишете програма, която чете в няколко низа и отпечатва само онези,
// завършващи на „r“ или „ay“. Само малки букви трябва да се имат предвид.

void printRandAY(std::ifstream& in);

int main()
{
  std::string filename = "Task2.txt";
  std::ifstream in(filename);

  printRandAY(in);

  in.close();

  return 0;
}

void printRandAY(std::ifstream& in)
{
  std::string str;
  std::vector<std::string> strBuff(0);

  while(getline(in, str))
  {

    if(str.find_last_of("ay") == (str.length() - 1) )
    {
      strBuff.push_back(str);
    }
    else if(str.find_last_of("r") == ( str.length() - 1) )
    {
      strBuff.push_back(str);
    }
  }

  for(auto i : strBuff)
  {
    std::cout << i << std::endl;
  }

}