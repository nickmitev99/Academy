/*
4. Напишете програма, която приема 10 цели числа от
клавиатурата, запазва ги в масив и ги принтира в обратен ред.
*/
#include <stdio.h>

#define SIZE 10

void printReverse(int* aInts, int size);

int main()
{
    int aInts[SIZE] = { 0 };

    printReverse(aInts, SIZE);

    return 0;
}

void printReverse(int* aInts, int size)
{
    int i = 0;

    for( ; i < size; i++)
    {
        printf("Enter a value for aInts[%d]: ", i);
        scanf("%d", &aInts[i]);                                       
    }

    i--;

    for(int j = 0; i >= 0, j < size; i--, j++)
    {
        printf("aInts[%d]: %d\n", j, aInts[i]);
    }
}