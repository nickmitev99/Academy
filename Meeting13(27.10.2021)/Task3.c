/*
Задача 3. Напишете програма, която проверява дали две дадени матрици са
еднакви, сравнявайки съответните елементи в тях. Разпечатайте в конзолата
двете изходни матрици и резултата от сравнението.
*/

#include <stdio.h>
#include "Functions.h"

#define ROWS 2
#define COLS 2

int compare2DArray(int from1[][COLS], int from2[][COLS], int size1, int size2);

int main()
{
    int iArr1[ROWS][COLS] = { 0 };
    int iArr2[ROWS][COLS] = { 0 };
    
    setMatrix(*iArr1, ROWS, COLS);
    putchar('\n');
    setMatrix(*iArr2, ROWS, COLS);
    putchar('\n');

    if(compare2DArray(iArr1, iArr2, ROWS, ROWS))
    {
        printf("The two arrays are different.");
    }
    else
    {
        printf("The two arrays are the same.");
    }

    return 0;
}

int compare2DArray(int arr1[][COLS], int arr2[][COLS], int size1, int size2)
{
    if(size1 != size2)
    {
        return 1;
    }

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(arr1[i][j] != arr2[i][j])
            return 1;
        }
    }

    return 0;
}