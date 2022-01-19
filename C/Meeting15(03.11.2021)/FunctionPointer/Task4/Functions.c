#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Functions.h"

void menu()
{
    int flag = 0;
    char cChoice = 'y';
    int *aiNums = (int*)malloc(sizeof(int));
    void (*fPtr)(int*, int, int) = sort;
    int iCount = 0, iPrev = 0, iDir = 0;
    
    while(1)
    {
        system("cls");
        printf("--ARRAY SORTER--\n");
        printf("Select the sorting order:\n");
        printf("1. Descending\n");
        printf("2. Ascending\n");
        printf("Anything else to quit\n");
        scanf("%d", &iDir);

        if(iDir < 1 || iDir > 2)
        {
            break;
        }

        if(flag == 1)
        {
            system("cls");
            printf("\nWould you like more elements?\n(y for yes, anything else for no): ");
            cChoice = getch();
            putchar('\n');
        }

        if(cChoice == 'y')
        {
            system("cls");
            printf("\nEnter how many elements you would like (Enter 0 or less to exit): ");
            scanf("%d", &iCount);

            if(iCount < 1)
            {
                break;
            }

            if(iPrev < iCount)
            {
                aiNums = (int*)realloc(aiNums, iCount * sizeof(int));
                setArray(aiNums, iCount);
            }
            else if(iPrev > iCount)
            {
                aiNums = (int*)realloc(aiNums, iCount * sizeof(int));
            }
        }

        sort_array(aiNums, iCount, iDir, *fPtr);

        system("cls");
        printArray(aiNums, iCount);
        putchar('\n');

        iPrev = iCount;
        flag = 1;
        system("pause");
    }

    free(aiNums);
}

void setArray(int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("Enter a value for aInts[%d]: ", i);
        scanf("%d", &arr[i]);                                       
    }
}

void printArray(int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("Element %d: %d\n", i+1, arr[i]);
    }
}

void sort_array(void* A, int n, int dir, void (*fp)(int*, int, int))
{
    fp(A, n, dir);
}

void sort(int* A, int n, int dir)
{
    int index = 0;

    for(int i = 0; i < n; i++)
    {
        index = i;

        for(int j = i; j < n; j++)
        {
            if(dir == 1)
            {
                if(A[index] < A[j])
                {
                    index = j;
                }
            }
            else if(dir == 2)
            {
                if(A[index] > A[j])
                {
                    index = j;
                }
            }
        }
        swapElements(&A[i], &A[index]);
    }
}

void swapElements(int* min, int* max)
{
    int temp = 0;

    temp = *min;
    *min = *max;
    *max = temp;
}