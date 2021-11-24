// Задача 3. Дефинирайте потребителски тип към указател.Създайте променлива,
// насочете указателя към нея, използвайки новия потребителски тип.

#include <stdio.h>

typedef int* intPtr;

int main()
{
    int iNum = 0;
    intPtr iPtr = NULL;

    printf("Enter an int: ");
    scanf("%d", &iNum);

    iPtr = &iNum;

    printf("\nYour number is: %d", *iPtr);

    return 0;
}