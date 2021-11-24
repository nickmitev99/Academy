/*
Задача 4. Напишете програма, която сумира редовете и колоните на въведена
от потребителя матрица. Разпечатайте матрицата и резултатите в конзолата.
*/

#include <stdio.h>
#include "Functions.h"

#define ROWS 2
#define COLS 2

void addRowAndColumn(int to[][COLS+1], int from[][COLS]);

int main()
{
    int iArr[ROWS][COLS] = { 0 };
    int iArrCombined[ROWS+1][COLS+1] = { 0 };
    
    setMatrix(*iArr, ROWS, COLS);

    addRowAndColumn(iArrCombined, iArr);

    putchar('\n');
    printMatrix(*iArr, ROWS, COLS);
    putchar('\n');
    printMatrix(*iArrCombined, ROWS+1, COLS+1);

    return 0;
}

void addRowAndColumn(int to[][COLS+1], int from[][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            to[i][j] = from[i][j];
            to[i][COLS] += from[i][j];
            to[ROWS][j] += from[i][j];
            to[ROWS][COLS] += (2*from[i][j]);
        }
    }
}