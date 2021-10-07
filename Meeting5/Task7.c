/*Задача 14. Напишете глобална променлива , която увеличаваме с 1 във
функция void test(). Извикайте функцията три пъти test() от main()
принтирайте стойността на глобалната променлива
*/

#include <stdio.h>

int test(int *num);

int gValue = 0;

int main()
{
    for(int i = 0; i < 3; i++)
    {
        test(&gValue);
    }

    printf("Size of gValue: %d\n", gValue);

    return 0;
}

int test(int *num)
{
    return (*num)++;
}