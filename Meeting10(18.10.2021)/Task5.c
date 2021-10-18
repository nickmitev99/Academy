/*
Задача 5. Рекурсивна функция
#include <stdio.h>
int RecursiveFun(int nA, int nB) {
int nValue = 1;
if (nA > 1 && nB > 1) {
nValue += RecursiveFun(nA
1, nB 1);
}
return (nA + nB + nValue);
}
int main() {
printf("RecursiveFun: %d
n", RecursiveFun(5, 7));
}
*/

#include <stdio.h>

int RecursiveFun(int nA, int nB) 
{
    int nValue = 1;
    if (nA > 1 && nB > 1) 
    {
        nValue += RecursiveFun(nA - 1, nB - 1);
    }

    return (nA + nB + nValue);
}

int main() 
{
    printf("RecursiveFun: %d\n", RecursiveFun(5, 7));

    return 0;
}