// Задача 6. Напишете функцията int linear_search(const int a[], int n, int key);
// използвайки адресна аритметика без инкрементиращи променливи.

#include <stdio.h>
#include "Functions.h"

#define SIZE 5

int linear_search(const int a[], int n, int key);

int main()
{
    int iaNums[SIZE] = { 0 };
    int iNum = 0, iSearch = 0;

    setArray(iaNums, SIZE);
    putchar('\n');
    printArray(iaNums, SIZE);
    putchar('\n');

    printf("Enter a number to search: ");
    scanf("%d", &iNum);

    iSearch = linear_search(iaNums, SIZE, iNum);

    if( iSearch != -1 )
    {
        printf("Element %d found at position %d\n", iNum, iSearch );
    }
    else
    {
        printf("Element not found");
    }

    return 0;
}

int linear_search(const int a[], int n, int key)
{
    const int* size = (a+n);
    const int* p = a;

    while(p < size)
    {
        if(*p == key)
        {
            return (p-a);
        }

        p++;
    }

    return -1;
}