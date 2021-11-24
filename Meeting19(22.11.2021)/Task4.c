// Задача 4. Използвайте предефинирани макроси

#include <stdio.h>

int main() 
{
    printf("File : %s\n", __FILE__ ); /* текущ файл */
    printf("Time : %s\n", __TIME__ ); /* време */
    printf("Date : %s\n", __DATE__ ); /* дата */
    printf("Line : %d\n", __LINE__ ); /* ред */
    printf("ANSI : %d\n", __STDC__ ); /* ANSI */

    return 0;
}