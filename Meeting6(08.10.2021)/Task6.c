/*
Упражнение 15. Логически оператори 
// опитайте различни комбинации
*/

#include <stdio.h>

int main() 
{
    int nA = 0;
    int nB = 0;
    int nX = 0;
    int nY = 0;

    printf("Enter the 1st number: ");
    scanf("%d", &nA);

    printf("Enter the 2nd number: ");
    scanf("%d", &nB);

    printf("Enter the 3rd number: ");
    scanf("%d", &nX);

    printf("Enter the 4th number: ");
    scanf("%d", &nY);

    if ( nA > nB && nA !=0 )                                            //Примерни стойности: nA = 1, nB = 0
    {
        printf("&& Operator : Both conditions are true\n");
    }

    if ( nX > nY || nY != 20)                                           //Примерни стойноси: nX = 1, nY = 1
    {
        printf("|| Operator : Only one condition is true\n");
    }

    if ( ( !(nA > nB) && (nB != 0) ) )                                  //Примерни стойности: nA = 1, nB = 1
    {
        printf(" ! Operator : Both conditions are true\n");
    }

    if ( (!(nA < nB)) && (nB > ~nB) )                                   //Примерни стойности: nA = 1, nB = 1
    {
        printf("~ Operator : Both conditions are true\n");
    }

    if( ( ( ! (nA < nB) ) ? 1 : 0) && ( (nB != 0) ? 1 : 0 ) )           //Примерни стойности: nA = 2, nB = 1
    {
        printf("? Operator : Both conditions are true\n");
    }

    if( (nX % nY == 0) || (nY % 2 != 0 ) )                              //Примерни стойности: nX = 1, nY = 1
    {
        printf("%% Operator : Only one condition is true\n");
    }

    if( (nA == nB) || (~nA == nB ) )                                    //Примерни стойности: nA = -1, nB = 1
    {
        printf("== Operator : Only one condition is true\n");
    }

    if( (nA == nB) && (nA > nX) && (nB < nY) && ( (nY-2) == nX ) )      //Примени стойности:
    {                                                                   //nA = 1, nB = 1, nX = 0, nY = 2
        printf("Mixed operators: The three conditions are true.\n");
    }

    return 0;
}