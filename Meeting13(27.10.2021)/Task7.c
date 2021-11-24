/*
Задача 7*. Напишете програма, която печата броя на уникалните редове в
бинарна матрица, съставена само от единици и нули.
*/

#include <stdio.h>
#include "Functions.h"

#define ROWS 3
#define COLS 3

void findUnique(int (*p)[COLS]);

int main()
{
    int iArr[ROWS][COLS] = { 0 };

    setMatrix(*iArr, ROWS, COLS);
    putchar('\n');
    
    printMatrix(*iArr, ROWS, COLS);
    putchar('\n');

    findUnique(iArr);

    return 0;
}

void findUnique(int (*p)[COLS])
{
    int aiLine[ROWS];
    int iNum = 0, iLast = COLS-1, iCounter = 0, k = 0;

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if( (p[i][j] != 0) && (p[i][j] != 1) )
            {
                printf("The matrix isn't binary!");
                return;
            }

            iNum |= p[i][j];
            iNum <<= 1;

            if(j == iLast)
            {
                aiLine[k] = iNum;
                iNum = 0;
                k++;
            }
        }
    }

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            iNum |= p[i][j];
            iNum <<= 1;
        }

        for(int x = 0; x < ROWS; x++)
        {
            if(iNum == aiLine[x])
            {
                iCounter++;
            }
        }

        if(iCounter == 1)
        {
            printf("Unique: ");
            for(int y = 0; y < COLS; y++)
            {
                printf("%d  ", p[i][y]);
            }
            putchar('\n');
        }

        iCounter = 0;
        iNum = 0;
    }
}