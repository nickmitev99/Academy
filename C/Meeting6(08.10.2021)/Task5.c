/*
Упражнение 14. Relational operators
#include <stdio.h>
int main() {
int nX = 33; // homework, input with scanf
int nY = 20;
if (nX == nY) {
printf("%d and %d are equal\n", nX, nY);
} else {
printf("%d and %d are not equal\n", nX, nY);
}
if (nX > nY) { printf("%d is greater than %d\n", nX, nY);
}
} // използвайте и останалите оператори за сравнение 
*/

#include <stdio.h>

void compareNums(const int nX, const int nY);

int main() 
{
    int nX = 0; 
    int nY = 0;

    printf("Enter the first number: ");
    scanf("%d", &nX);

    printf("Enter the second number: ");
    scanf("%d", &nY);

    compareNums(nX, nY);

    return 0;
}

void compareNums(const int nX, const int nY)
{
    if (nX >= nY)
    {
        printf("%d is greater or equal to %d\n", nX, nY);
    }

    if (nX > nY) 
    { 
        printf("%d is greater than %d\n", nX, nY);
    }

    if (nX <= nY)
    {
        printf("%d is less or equal to %d\n", nX, nY);
    }

    if (nX < nY)
    {
        printf("%d is less than %d\n", nX, nY);
    }

    if (nX == nY) 
    {
        printf("%d and %d are equal\n", nX, nY);
    } 

    if (nX != nY)
    {
        printf("%d is not equal to %d\n", nX, nY);
    }
}