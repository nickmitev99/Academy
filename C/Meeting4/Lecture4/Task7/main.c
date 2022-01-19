#include<stdio.h>

int main()
{
    short int iValue1 = 24212;
    int iValue2 = -1357674;
    int iValue3 = 1357674;
    long int iValue4 = -1357674000;
    unsigned long int iValue5 = 3657895000;
    //-1357674 1357674 -1357674000 3657895000

    printf("%hd\n", iValue1);
    printf("%d\n", iValue2);
    printf("%d\n", iValue3);
    printf("%ld\n", iValue4);
    printf("%lu\n", iValue5);

    return 0;
}

/*Дефинирайте променливи със стойност 24 212, -1 357 674, 1 357 674, -1 357
674 000, 3 657 895 000.
Изведете всяка променлива на екрана със printf()*/