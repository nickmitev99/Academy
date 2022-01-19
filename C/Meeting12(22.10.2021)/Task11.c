/*
11. Напишете програма, която сортира масив, въведен от клавиатурата,
използвайки указатели.
*/

#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

#define SIZE 5

void menu();
void sortArrayDescending(int *pNum, int size);
void sortArrayAscending(int *pNum, int size);
void swapNums(int *const first, int *const second);

int main()
{
    menu();

    return 0;
}

void menu()
{
    int arr[SIZE] = { 0 };
    int *p = arr;
    char cChoice = 0;

    do
    {
        system("cls");
        fflush(stdin);

        printf("\nIn what order would you like to sort the array?\n");
        printf("1. Descending.\n");
        printf("2. Ascending.\n");
        printf("Press anything else to exit.\n");
        scanf("%c", &cChoice);
        
        switch(cChoice)
        {
            case '1':
                system("cls");

                setArray(p, SIZE);

                sortArrayDescending(p, SIZE);

                printf("\nSorted array:\n");
                printArray(p, SIZE);

                system("pause");
                break;

            case '2':
                system("cls");

                setArray(p, SIZE);

                sortArrayAscending(p, SIZE);

                printf("\nSorted array:\n");
                printArray(p, SIZE);

                system("pause");
                break;

            default:
                system("cls");
                printf("Exiting program.\n");
                return;
        }
    } while (1);
}

void sortArrayDescending(int *pNum, int size)
{
    int pos = 0;

    for(int i = 0; i < size; i++)
    {
        pos = i;

        for(int j = i; j < size; j++)
        {
            if(*(pNum+pos) < *(pNum+j) )
            {
                pos = j;
            }
        }

        swapNums((pNum + i), (pNum + pos) );
    }
}

void sortArrayAscending(int *pNum, int size)
{
    int pos = 0;

    for(int i = 0; i < size; i++)
    {
        pos = i;

        for(int j = i; j < size; j++)
        {
            if(*(pNum+pos) > *(pNum+j) )
            {
                pos = j;
            }
        }

        swapNums((pNum + i), (pNum + pos) );
    }
}

void swapNums(int *const first, int *const second)
{
    int temp = *first;

    *first = *second;
    *second = temp;
}