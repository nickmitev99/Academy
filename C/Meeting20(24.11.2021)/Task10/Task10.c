// Задача 10. Изместете позицията си във файла 7 байта след
// началото, ползвайки fseek.
// int fseek(FILE *pfile, long offset, int original);

#include <stdio.h>

#define SIZE 30

int main()
{
    FILE* fp = NULL;
    char strOutput[SIZE] = { 0 };

    if( ( fp = fopen("Task10.txt", "r+") ) == NULL)
    {
        printf("Can not open the file for input and output");
        return -1;
    }

    fseek(fp, 7, SEEK_SET);

    fscanf(fp, "%[^\n]", strOutput);
    printf("The file's output without the first 7 characters is '%s'", strOutput);

    fclose(fp);

    return 0;
}