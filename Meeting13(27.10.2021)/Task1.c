/*
Задача 1. Декларирайте двумерен масив с по 5 елемента (5 x 5). След като
сте готови, направете въвеждане на данните в масива, като четете от
потребителя със scanf. Отпечатайте масива в конзолата, спазвайки броя
редове и колони.
*/

#include <stdio.h>

#define ROWS 2
#define COLS 2

void set2DArray(int arr[][COLS], int rows);
void print2DArray(int arr[][COLS], int rows);

int main()
{
    int iArr[ROWS][COLS] = { 0 };
    
    set2DArray(iArr, ROWS);
    print2DArray(iArr, ROWS);

    return 0;
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