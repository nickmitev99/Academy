/*Задача 6. Запишете в четири последователни байтове в паметта със
стойност 0xAA(10101010) и разпечатайте съдържанието на горните байтове,
ако типът е: float, signed int, unsigned int*/

#include <stdio.h>


void fillArray(unsigned char* array, int size);
void printSigned(unsigned char* array, int size);
void printFloat(unsigned char* array, int size);
void printUnsigned(unsigned char* array, int size);


int main()
{
    unsigned char aArray[4];
    int iSize = sizeof(aArray);

    fillArray(aArray, iSize);
    printFloat(aArray, iSize);
    printSigned(aArray, iSize);
    printUnsigned(aArray, iSize);


    return 0;
}


void fillArray(unsigned char* array, int size)
{
    while(size > 0)
    {
        size--;
        array[size] = 0xAA;
    }
}

void printSigned(unsigned char* array, int size)
{
    printf("Signed int: ");

    while(size > 0)
    {
        size--;
        printf("%d ", array[size]);
    }

    printf("\n");
}

void printUnsigned(unsigned char* array, int size)
{
    printf("Unsigned int: ");

    while(size > 0)
    {
        size--;
        printf("%u ", (unsigned int) array[size]);
    }

    printf("\n");
}

void printFloat(unsigned char* array, int size)
{
    printf("Float: ");

    while(size > 0)
    {
        size--;
        printf("%f ", (float) array[size]);
    }

    printf("\n");
}