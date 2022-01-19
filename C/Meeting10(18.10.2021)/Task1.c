/*
Задача 1. Напишете функция , която печата низ . Пойнтер ът към
началото му е подаден като аргумент на функцията void printstr (char *s); Не
забравяйте , низът винаги завършва с знак за терминираща нула 0', затова
проверката в цикъла , който принтира всеки символ , трябва да е докато не се
стигне този знак
*/

#include <stdio.h>

void printStr(char *pStr);

int main()
{
    char sStr[20] = { 0 }; 
    printf("Enter a string: ");
    scanf("%s", sStr);

    printStr("\nPrinting the output of func printStr(sStr): \n");
    printStr(sStr);

    return 0;
}

void printStr(char* pStr)
{
    while(*pStr)
    {
        putchar(*pStr);
        pStr++;
    }
}