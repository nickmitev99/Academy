#include <stdio.h>

int main(void)
{
    char cValue1 = -127;
    unsigned char cValue2 = 255;
    unsigned short int iValue1 = 63498;
    unsigned long int iValue2 = 4294967292;
    long long int iValue3 = -9000000000000775845;

    printf("%d\n", cValue1);
    printf("%d\n", cValue2);
    printf("%hu\n", iValue1);
    printf("%lu\n", iValue2);
    printf("%lld\n", iValue3);


    return 0;
}

/*Дефинирайте променливи със стойност -127, 255, 63 498, 4 294 967 292, -9 000
000 000 000 775 845.
Изведете всяка променлива на екрана със printf()*/