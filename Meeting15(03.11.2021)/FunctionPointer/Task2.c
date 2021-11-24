// Задача 2. Добавете към горния код функции за умножение и деление.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fnPlus(int a, int b);
int fnMinus(int a, int b);
int fnMultiply(int a, int b);
double fnDivide(int a, int b);

int main(int argc, char* argv[])
{
    int (*pfCalc)(int, int) = NULL;
    double (*pfDivide)(int, int) = NULL;

    if(argc != 4)
    {
        return 1;
    }

    if( !strcmp(argv[2], "+") )
    {
        pfCalc = fnPlus;

        printf("%s + %s = %d", argv[1], argv[3], (*pfCalc)( atoi(argv[1]), atoi(argv[3]) ) );
    }
    else if( !strcmp(argv[2], "-") )
    {
        pfCalc = fnMinus;

        printf("%s - %s = %d", argv[1], argv[3], (*pfCalc)( atoi(argv[1]), atoi(argv[3]) ) );
    }
    else if( !strcmp(argv[2], "x") )
    {
        pfCalc = fnMultiply;

        printf("%s * %s = %d", argv[1], argv[3], (*pfCalc)( atoi(argv[1]), atoi(argv[3]) ) );
    }
    else if( !strcmp(argv[2], "/") )
    {
        pfDivide = fnDivide;

        printf("%s / %s = %lf", argv[1], argv[3], (*pfDivide)( atof(argv[1]), atof(argv[3]) ) );
    }
}

int fnPlus(int a, int b)
{
    return (a+b);
}

int fnMinus(int a, int b)
{
    return (a-b);
}

int fnMultiply(int a, int b)
{
    return (a*b);
}

double fnDivide(int a, int b)
{
    return ( (double)(a) / b );
}

