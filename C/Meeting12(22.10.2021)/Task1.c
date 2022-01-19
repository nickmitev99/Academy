/*
1. Напишете програма, която въвежда и принтира елементитe на масив,
използвайки указател.
*/

#include <stdio.h>
#include "Functions.h"

#define SIZE 5

int main()
{
    int arr[SIZE] = { 0 }, *p = arr;

    setArray(arr, SIZE);
    putchar('\n');
    printArray(arr, SIZE);

    return 0;
}