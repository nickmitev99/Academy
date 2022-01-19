/*
5. Напишете програма, която принтира уникалните елементи от
масив с цели числа, въведени от клавиатурата. За целта, някои
от числата трябва да се повтарят
*/

#include <stdio.h>
#include "Functions.h"

#define SIZE 10

void findUnique(int* aInts, int size);

int main()
{
    int aInts[SIZE] = { 0 };

    setArray(aInts, SIZE);

    putchar('\n');

    findUnique(aInts, SIZE);

    return 0;
}

void findUnique(int* aInts, int size)
{
    int iNum = 0, isUnique = 0;
    static int i = 0;

    for(i = 0; i < size; i++)
    {
        int temp = aInts[i];

        for(int j = 0; j < size; j++)
        {
            if( (aInts[j] == temp) && (j != i) )
            {
                isUnique = 0;
                break;
            }
            else
            {
                isUnique = 1;
            }
        }

        if(isUnique)
        {
            printf("Unique: %d\n", aInts[i]);
        }
    }
}
