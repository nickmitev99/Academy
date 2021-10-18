/*
Упражнение 18* Направете бягаща светлина, като приемете, че всеки бит от
дадена променлива, е свързан с лампа (или светодиод). Когато битът е
нула, лампата не свети, когато е единица свети.
Примерно, ако генерирате последователност:
1, 2, 3, 4, се получава следното:
1 *....................
2 .*...................
4 ..*..................
8 ...*................. ...
За да генерирате закъснение, използвайте следната функция от C runtime:
#include <unistd.h>
unsigned int sleep(unsigned int seconds);
*/
#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>


int main() 
{
    int iStart = 0;
    int iEnd = 7;
    for (int i = iStart; i <= iEnd; i++)
    {
        system("cls");

        for(int j = iStart; j < i; j++)
        {
            if(j != i)
            {
                printf(".");
            }
        }

        printf("*");

        for(int k = iEnd; k > i; k--)
        {
            if(k != i)
            {
                printf(".");
            }
        }
        
        sleep(1);
    }

    printf("\n");
    system("pause");
    

    return 0;
}