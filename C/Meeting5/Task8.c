/*Задача 15. Използвайте статична локална променлива , за да постигнете
същото поведение , описано в задача 14.
*/

#include <stdio.h>

int test();

int main()
{
    

    for(int i = 0; i < 2; i++)
    {
        test();
    }

    printf("Size of sValue: %d\n", test());

    return 0;
}

int test()
{
    static int sValue = 0;
    sValue +=1;
    return sValue;
}