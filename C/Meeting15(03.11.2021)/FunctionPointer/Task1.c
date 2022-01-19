// Задача 1. Направете две функции и извикайте желаната функция с указател
// към функция, съобразно знака, подаден от командния ред:
// Пример: а.exe 20 + 3
// #include <stdio.h>
// #include <stdlib.h>
// int fnPlus(int nA, int nB) { return(nA + nB); }
// int fnMinus(int nA, int nB) { return(nA - nB); }
// int ( * pfCalc ) ( int, int ) = NULL;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fnPlus(int a, int b);
int fnMinus(int a, int b);

int main(int argc, char* argv[])
{
    int (*pfCalc)(int, int) = NULL;

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
}

int fnPlus(int a, int b)
{
    return (a+b);
}

int fnMinus(int a, int b)
{
    return (a-b);
}