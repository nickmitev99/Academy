// Задача 5. Пренапишете алгоритъма за сортиране без да използвате
// инкрементиращи променливи.
// void sort ( int a[], int n){
// int i = 0, j = 0, temp = 0;
// for ( i = 0; i < n - 1; ++i ){
// for ( j = i + 1; j < n; ++j ){
// if ( a[i] > a[j] ) {
// temp = a[i];
// a[i] = a[j];
// a[j] = temp;
// }
// }
// }

#include <stdio.h>
#include "Functions.h"

#define SIZE 5

void sort(int a[], int n);

int main()
{
    int iaNums[SIZE] = { 0 };
    int *p = iaNums;

    setArray(p, SIZE);
    putchar('\n');

    sort(p, SIZE);
    
    printArray(p, SIZE);
    
    return 0;
}

void sort(int a[], int n)
{
    int temp = 0;
    int *a2 = (a+1);
    int *size = (a+n);

    while(a < (size-1) )
    {
        a2 = (a+1);

        while(a2 < size)
        {
            if( *a > *a2 )
            {
                temp = *a;
                *a = *a2;
                *a2 = temp;
            }

            a2++;
        }
        
        a++;
    }
}