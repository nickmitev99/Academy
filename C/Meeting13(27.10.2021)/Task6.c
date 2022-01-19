/*
Задача 6*. Напишете програма, която търси дадено число в сортирана по
редове матрица. Генерирайте елементите на матрицата с rand(). Принтирайте
матрицата и въведете от клавиатурата търсеното число. Покажете позицията
му.
*/

#include <stdio.h>
#include "Functions.h"

#define ROWS 3
#define COLS 2

void sortMatrix(int *p, int rows, int cols);
void swapElements(int* min, int* max);
void searchNum(int (*p)[COLS], int num);

int main()
{
    int iArr[ROWS][COLS] = { 0 };
    int iNum = 0;
    
    setMatrix(*iArr, ROWS, COLS);

    sortMatrix(*iArr, ROWS, COLS);

    printf("\nSorted matrix:\n");
    printMatrix(*iArr, ROWS, COLS);

    printf("Enter a number to search in the matrix: ");
    scanf("%d", &iNum);
    
    putchar('\n');
    searchNum(iArr, iNum);

    return 0;
}

void sortMatrix(int *p, int rows, int cols)
{
    int size = rows * cols;
    int pos = 0;

    for(int i = 0; i < size; i++)
    {
        pos = i;

        for(int j = i; j < size; j++)
        {
            if(p[pos] > p[j])
            {
                pos = j;
            }
        }
        swapElements(&p[i], &p[pos]);
    }
}

void swapElements(int* min, int* max)
{
    int temp = 0;

    temp = *min;
    *min = *max;
    *max = temp;
}

void searchNum(int (*p)[COLS], int num)
{
    int isFound = 0;
    int pos = -1;

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            pos++;

            if(p[i][j] == num)
            {
                printf("The number '%d' is in position [%d][%d] (position %d in the matrix)", num, i, j, pos);
                isFound = 1;
            }
        }
    }

    if(!isFound)
    {
        printf("The number '%d' isn't in the array", num);
    }
}