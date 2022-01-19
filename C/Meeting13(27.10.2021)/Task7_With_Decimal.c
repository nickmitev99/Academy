/*
Моя версия на задача 7, но с десетични числа вместо бинарни
*/

#include <stdio.h>
#include "Functions.h"

#define ROWS 3
#define COLS 2

void findUnique(int (*p)[COLS]);

int main()
{
    int iArr[ROWS][COLS] = { 0 };

    setMatrix(*iArr, ROWS, COLS);
    printMatrix(*iArr, ROWS, COLS);

    findUnique(iArr);

    return 0;
}

void findUnique(int (*p)[COLS])
{
    int isUnique = 0;
    int pos = -1;

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < ROWS; j++)
        {
            isUnique = 0;
            pos = -1;

            for(int k = 0; k < COLS; k++)
            {
                if( (p[i][k] != p[j][k]) && (i != j) )
                {
                    isUnique = 1;
                    pos = i;
                }
                if( (p[i][k] == p[j][k]) && (i != j) )
                {
                    isUnique = -1;
                    break;
                }
                if(p[ROWS-1][k] == p[i][k])                     //If the last number is unique, this if statement will run, if it 
                {                                               //isn't unique, it will break on line 40
                    for(int z = 0; z < ROWS-1; z++)
                    {
                        if( (p[ROWS-1][k] != p[z][k]) )
                        {
                            isUnique = 1;
                            pos = ROWS - 1;
                        }
                    }
                }
            }

            if(isUnique == -1)
            {
                break;
            }
        }

        if( (isUnique == 1) && (pos >= 0) )
        {
            printf("Unique: ");
            for(int j = 0; j < COLS; j++)
            {
                printf("%d   ", p[pos][j]);
            }
            putchar('\n');
        }

    }
}