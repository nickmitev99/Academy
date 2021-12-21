// Задача 4. Прочетете цял стринг от създадения вече файл, като използвате:
// char *fgets(char * str, int nchars, FILE *stream).
// Принтирайте прочетения стринг на екрана.

#include <stdio.h>

#define SIZE 30

int main()
{
    FILE* fp = NULL;
    char strInput[SIZE] = { 0 };

    if( ( fp = fopen("Task4.txt", "r+") ) == NULL)
    {
        printf("Can not open the file for input and output");
        return -1;
    }

    fgets(strInput, SIZE, fp);
    fputs(strInput, stdout);

    fclose(fp);

    return 0;
}