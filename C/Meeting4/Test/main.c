#include <stdio.h>

int main(void)
{
    int iNumA = 5, iNumB = 3, res = 0;

    res = iNumA & iNumB;
    printf("A & B : %d \n", res);

    res ^= res;
    res = iNumA | iNumB;
    printf("A | B: %d \n", res);

    res ^= res;
    res = iNumA ^ iNumB;
    printf("A ^ B: %d \n", res);

    return 0;
}