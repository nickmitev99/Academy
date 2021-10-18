/*
Упражнение 17* Направете генератор на случайни числа по следния
алгоритъм (xorshift):
int A = 1, акумулатор с начална стойност
При всяко вземане на число от генератора се прави следното:
(i) A ^= A << 13;
(ii) A ^= A >> 17;
(iii) A ^= A << 5;
При всяка итерация изведете числото на екрана.
(Направете вариация с акумулатор long long int)
*/

#include <stdio.h>

void randomI(int *iNumA);
void randomLL(long long int *iNumB);

int main() 
{
    int iNumA = 0;
    long long int iNumB = 0;

    printf("Enter a int to be randomly shifted: ");                 //До числото 8191 няма разлика в резултата
    scanf("%d", &iNumA);                                            //след това int-а се препълва и започва преброяване

    printf("Enter a long long int to be randomly shifted: ");
    scanf("%lld", &iNumB);

    randomI(&iNumA);
    randomLL(&iNumB);

    printf("\niNumA: %d", iNumA);
    printf("\niNumB: %lld", iNumB);

    return 0;
}

void randomI(int *iNumA)
{
    *iNumA ^= *iNumA << 13;
    printf("\niNumA: << 13: %d\n", *iNumA);
    *iNumA ^= *iNumA >> 17;
    printf("iNumA: >> 17: %d\n", *iNumA);
    *iNumA ^= *iNumA << 5;
    printf("iNumA: << 5: %d\n", *iNumA);
}

void randomLL(long long int *iNumB)
{
    *iNumB ^= *iNumB << 13;
    printf("\niNumB: << 13: %lld\n", *iNumB);
    *iNumB ^= *iNumB >> 17;
    printf("iNumB: >> 17: %lld\n", *iNumB);
    *iNumB ^= *iNumB << 5;
    printf("iNumB: << 5: %lld\n", *iNumB);
}