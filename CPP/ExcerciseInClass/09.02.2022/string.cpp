#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>

std::ostream& newL(std::ostream& out);

void displayStringTest()
{
  std::cout << "--Strings--" << std::endl;

  std::string s = "Hello!";
  int len = s.length();
  char ch1 = s.at(1);
  char ch2 = s[1];

  std::cout << "String: " << s << std::endl;
  std::cout << "Length: " << len << std::endl;
  std::cout << "ch1: " << ch1 << std::endl;
  std::cout << "ch2: " << ch2 << std::endl;

  std::string fName = "Nikolay";
  std::string lName = "Mitev";

  std::string name = fName + " " + lName;

  std::cout << name << std::endl;

  std::string stringche = name + ": C++ " + "is powerful!";
  std::cout << stringche << std::endl;

  name.append("4");

  std::cout << name << std::endl;
  std::cout << name.length() << std::endl;

  std::string s1 {"Apple"};
  std::string s2 {"Banana"};
  std::string s3 {"apple"};
  std::string s4 {s2};
  std::string s5 {"Apple", 3, 2};
  std::string s6 ("Orange");
  std::string s7 (10, 'x');

  std::cout << std::boolalpha;

  std::cout << s1 << " == " << s5 << ": " << (s1 == s5) << std::endl;
  std::cout << s1 << " == " << s3 << ": " << (s1 == s3) << std::endl;
  std::cout << s1 << " != " << s2 << ": " << (s1 != s2) << std::endl;
  std::cout << s1 << " < " << s4 << ": " << (s1 < s4) << std::endl;
  std::cout << s1 << " > " << s7 << ": " << (s1 > s7) << newL << std::endl;

  std::cout << name.substr(0, 7) << std::endl;
  std::cout << name.substr(5, 4) << std::endl;
  std::cout << name.substr(10, 6) << std::endl;
  std::cout << name.find("ola") << std::endl;
  std::cout << name.find_first_of("Mit") << std::endl;
  std::cout << name.find_first_of("i") << std::endl;
  std::cout << name.find_last_of("i") << std::endl;
  std::cout << name.find_last_of("i", 5) << std::endl;

  system("cls");

  std::string cocktail("Vodka + Martini + Cherry");
  int pos = cocktail.find("+");

  std::cout << cocktail << newL;

  while(pos != std::string::npos)
  {
    cocktail.replace(pos, 1, "and");
    pos = cocktail.find("+", pos + 1);
  }

  std::cout << cocktail << newL;

  system("cls");

  // std::cout << "Please enter your full name: ";
  // std::getline(std::cin, name);
  // std::cout << "Hello, " << name << newL;

  char cStr[30] = { 0 };

  name.copy(cStr, name.length());

  cStr[strlen(cStr)] = '\0';

  std::cout << cStr << std::endl;

  strcpy(cStr, name.c_str());

  printf("%s\n", cStr);

  strcpy(cStr, name.data());

  printf("%s\n", cStr);

  system("cls");

  std::string str1 = "beginning end";
  std::string str2 = "middle";
  std::string str3 = "123456789";
  std::string str4 = "00";

  str1.insert(strlen("beginning "), str2);

  str3.insert(strlen("123"), str4, 0, std::string::npos);

  std::cout << str1 << newL;
  std::cout << str3 << newL;

  std::cout << str1.capacity() << newL;
  std::cout << str1.max_size() << newL;

  std::cout << str1.empty() << newL;

  str1.resize(60);
  std::cout << str1.capacity() << newL;
}