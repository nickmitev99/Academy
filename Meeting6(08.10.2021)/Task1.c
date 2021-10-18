/*
Задача 9: Условен оператор (?:)
#include <stdio.h>
int main()
{
int nA = 1;
int nB = (nA == 1) ? 2 : 0; 
printf("A value is %d\n", nA); printf("B value is %d\n", nB);
}
а) въведете стойност за nA с scanf
b) използвайте условния оператор за намиране на максималното от две числа
*/

#include <stdio.h>

int main()
{
    int nA = 0, nB = 0;
    int iBool;

    printf("Enter number A: ");
    scanf("%d", &nA);

    printf("Enter number B: ");
    scanf("%d", &nB);

    iBool = (nA > nB) ? 1 : 0;

    if(iBool)
    {
        printf("Number A is bigger.\n");
    }

    else if(nA == nB)
    {
        printf("The numbers are equal\n");
    }

    else
    {
        printf("Number B is bigger.\n");
    }

    return 0;
}