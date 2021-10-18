/*
Задача 2. Напишете функцията int atof(char *s), която
преобразува стринг в число с десетична запетая. Тази функция е
подобна на разглежданата по горе atoi(char *s), само че когато се
стигне до . точката, отделяща цялата част от дробната, трябва
да се пусне още един цикъл, който да изчисли числото в
дробната част по същия начин, както е числото в цялата част.
Само че тук при дробната част трябва да имаме една
променлива, която да умножаваме по 10 всеки път до края на
дробната част power *= 10; Накрая трябва да разделим
полученото число на тази променлива, за да получим реалното
число с плаващата запетая на точното място.
*/

#include <stdio.h>

double atof(char *pStr);

int main()
{
    char sStr[20] = { 0 }; 
    
    printf("Enter a floating point number: ");
    scanf("%s", sStr);

    printf("atof(%s): %.3lf\n", sStr, atof(sStr));

    return 0;
}

double atof(char *pStr)
{
    int beforePoint = 0;
    int afterPoint = 0;
    int power = 1;
    double num = 0.0;

    while(*pStr)
    {
        if(*pStr == '.')
        {
            pStr++;
            for( ; *pStr != '\0'; pStr++)
            {
                afterPoint = (10 * afterPoint) + (*pStr - '0');
                power *= 10;
            }
        }

        else
        {
            beforePoint = (10 * beforePoint) + (*pStr - '0');
        }

        pStr++;
    }

    num = (double)(afterPoint) / power;
    num += beforePoint;

    return num;
}