/*Задача 13. Ако имаме символен низ char str[] = “HELLO”, заменете
всичките символи с главна буква със съответните символи с малка
буква
*/

#include <stdio.h>

void toLower(unsigned char* array);

int main()
{
    unsigned char aArray[] = "HELLO!";
    int iSize = sizeof(aArray);

    printf("Before: %s\n", aArray);

    toLower(aArray);

    printf("After: %s\n", aArray);

    return 0;
}

void toLower(unsigned char* array)
{
    while(*array != '\0')
    {
        if(*array >= 'A' && *array <= 'Z')
        {
            *array += 32;
        }

        array++;
    }
}