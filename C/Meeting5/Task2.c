/*Задача 7. Запишете в осем последователни байта в паметта със
стойност 0xBB(1011 1011) и разпечатайте съдържанието на
горните байтове, ако типът е: double, signed long long, unsigned
long long*/
#include <stdio.h>


void fillArray(unsigned char* array, int size);
void printSignedLL(unsigned char* array, int size);
void printDouble(unsigned char* array, int size);
void printUnsignedLL(unsigned char* array, int size);


int main()
{
    unsigned char aArray[8];
    int iSize = sizeof(aArray);

    fillArray(aArray, iSize);
    printDouble(aArray, iSize);
    printSignedLL(aArray, iSize);
    printUnsignedLL(aArray, iSize);


    return 0;
}


void fillArray(unsigned char* array, int size)
{
    while(size > 0)
    {
        size--;
        array[size] = 0xBB;
    }
}

void printSignedLL(unsigned char* array, int size)
{
    printf("Signed long long int: ");

    while(size > 0)
    {
        size--;
        printf("%lld ", (long long int)array[size]);
    }

    printf("\n");
}

void printUnsignedLL(unsigned char* array, int size)
{
    printf("Unsigned long long int: ");

    while(size > 0)
    {
        size--;
        printf("%u ", (unsigned long long int) array[size]);
    }

    printf("\n");
}

void printDouble(unsigned char* array, int size)
{
    printf("Double: ");

    while(size > 0)
    {
        size--;
        printf("%f ", (double) array[size]);
    }

    printf("\n");
}