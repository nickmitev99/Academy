// Задача 2. Напишете макрос swap(t, x, y), койтo променя местата на двата 
// аргумента от тип t.

#include <stdio.h>

#define swap(t, x, y) t = x; x = y; y = t
#define print(x, y) printf("\niNumA: %d\niNumB: %d\n", iNumA, iNumB)

int main()
{
    int iNumA = 0, iNumB = 0, iTemp = 0;

    printf("Enter the first int: ");
    scanf("%d", &iNumA);

    printf("Enter the second int: ");
    scanf("%d", &iNumB);

    printf("\nBefore swap:");
    print(iNumA, iNumB);

    swap(iTemp, iNumA, iNumB);

    printf("\nAfter swap:");
    print(iNumA, iNumB);

    return 0;
}