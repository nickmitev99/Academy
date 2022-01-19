/*
Задача 5*. Напишете програма, която проверява дали дадена матрица е
identity matrix - матрица с размер (N x N), където само елементите в главния
диагонал са единици, а всички останали елементи са нули.
*/

#include <stdio.h>
#include "Functions.h"

#define SIZE 3

int isIdentityMatrix(int (*p)[SIZE], int rows, int cols);

int main()
{
    int iArr[SIZE][SIZE] = { 0 };
    
    setMatrix(*iArr, SIZE, SIZE);   //if SIZE is 3, input 1 0 0 0 1 0 0 0 1

    putchar('\n');
    printMatrix(*iArr, SIZE, SIZE);

    if( isIdentityMatrix(iArr, SIZE, SIZE) )
    {
        printf("The entered matrix is an identity matrix");
    }
    else
    {
        printf("The entered matrix isn't an identity matrix");
    }

    return 0;
}

int isIdentityMatrix(int (*p)[SIZE], int rows, int cols)
{
    int iCount = 0;

    if(rows != cols)
    {
        return 0;
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if( (i == j) && p[i][j] == 1)
            {
                iCount++;
            }
            else if(p[i][j] != 0)
            {
                return 0;
            }
        }
    }

    if(iCount == rows)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
