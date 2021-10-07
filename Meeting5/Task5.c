/*Задача 12. Ако имаме символен низ char str[] = “ H е llo ”, заменете
буквите l с х на същия символен низ и отпечатайте резултата на
конзолата
*/

#include <stdio.h>

void replaceL(unsigned char* array, int size);

int main()
{
    unsigned char aArray[] = "Hello!";
    int iSize = sizeof(aArray);

    printf("Before replacement: %s\n", aArray);

    replaceL(aArray, iSize);

    printf("After replacement: %s\n", aArray);

    return 0;
}


void replaceL(unsigned char* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        if (array[i] == 'l')
        {
            array[i] = 'x';
        }
    }
}