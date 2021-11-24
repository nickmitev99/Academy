/*
Задача 2. Напишете програма, която събира две матрици (4х4) и записва
резултата в трета такава със същия размер. Събирането на матриците
става като намерим сумата на съответстващите елементи в тях. Данните за
изходните матрици трябва да бъдат въведени от потребителя. Разпечатайте
трите матрици в конзолата.
*/

#include <stdio.h>
#include "Functions.h"

#define ROWS 2
#define COLS 2

void combine2DArray(int to[][COLS], int from1[][COLS], int from2[][COLS]);

int main()
{
    int iArr1[ROWS][COLS] = { 0 };
    int iArr2[ROWS][COLS] = { 0 };
    int iArrCombined[2*ROWS][COLS];
    
    setMatrix(*iArr1, ROWS, COLS);
    putchar('\n');
    setMatrix(*iArr2, ROWS, COLS);
    putchar('\n');
    
    combine2DArray(iArrCombined, iArr1, iArr2);

    printMatrix(*iArrCombined, 2*ROWS, COLS);

    return 0;
}

void combine2DArray(int to[][COLS], int from1[][COLS], int from2[][COLS])
{
    int i = 0;

    for(i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            to[i][j] = from1[i][j];
        }
    }

    for(int k = 0 ; k < ROWS; k++, i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            to[i][j] = from2[k][j];
        }
    }

}

void set2DArray(int arr[][COLS], int rows)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("Enter element[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }   
}

void print2DArray(int arr[][COLS], int rows)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("Element[%d][%d]: %d\n", i, j, arr[i][j]);
        }
    }   
}