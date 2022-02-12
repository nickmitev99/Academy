#include <iostream>
#include <string>
#include <algorithm>

// 3. Напишете програма, която въвежда низ и отпечатва Низa в обратен ред.
// Преобразувайте всички главни букви в малки букви и всички малки букви до
// главни. 

void transform(std::string &sRef);

int main()
{
  std::string str;

  std::cout << "Enter a string: ";
  std::cin >> str;

  std::cout << "Normal string: " << str << std::endl;

  transform(str);

  std::reverse(str.begin(), str.end());

  std::cout << "Reworked string: " << str << std::endl;

  return 0;
}

void transform(std::string &sRef)
{
  int iLenght = sRef.length();

  for(int i = 0; i < iLenght; i++)
  {
    if( (sRef[i] >= 'a') && (sRef[i] <= 'z') )
    {
      sRef[i] -= 32;
    }
    else if( (sRef[i] >= 'A') && (i <= 'Z') )
    {
      sRef[i] += 32;
    }
  }
}