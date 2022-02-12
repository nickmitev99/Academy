#include <iostream>
#include <string>

// 1. Някоя информация в Интернет може да е криптиранa с прост алгоритъм,
// известен като "rot13", който завърта всеки знак с 13 позиции в азбуката.
// По този начин "a" съответства на 'n' и 'x' съответства на 'k'. rot13 е пример на
// симетрично криптиране на ключове. Със симетричен ключ криптиране, както
// шифровъдството, така и дешифриращото използване на същия ключ.
// а) Напишете програма, която криптира съобщение с помощта на rot13.
// б) Напишете програма, която дешифрира кодираното съобщение,
// използващо 13 като ключ.

#define KEY 13

void encryptRot13(std::string &str);
void deCryptRot13(std::string &str, int key);

int main()
{
  std::string str = "Hello, nice to meet you!";

  encryptRot13(str);

  std::cout << "Encrypted msg: " << str << std::endl;

  deCryptRot13(str, 13);

  std::cout << "Decrypted msg: " << str << std::endl;

  return 0;
}

void encryptRot13(std::string &str)
{
  int iStrLen = str.length();

  for(int i = 0; i < iStrLen; i++)
  {
    if ( ( (str[i] >= 'a') && (str[i] <= 'm') ) || ( (str[i] >= 'A') && (str[i] <= 'M') ) )
    {
      str[i] += 13;
    }
    else if ( ( (str[i] >= 'n') && (str[i] <= 'z') ) || ( (str[i] >= 'N') && (str[i] <= 'Z') ) )
    {
      str[i] -= 13;
    }
  }
}

void deCryptRot13(std::string &str, int key)
{
  int iStrLen = str.length();

  for(int i = 0; i < iStrLen; i++)
  {
    if ( ( (str[i] >= 'a') && (str[i] <= 'n') ) || ( (str[i] >= 'A') && (str[i] <= 'N') ) )
    {
      str[i] += key;
    }
    else if ( ( (str[i] >= 'o') && (str[i] <= 'z') ) || ( (str[i] >= 'O') && (str[i] <= 'Z') ) )
    {
      str[i] -= key;
    }
  }
}