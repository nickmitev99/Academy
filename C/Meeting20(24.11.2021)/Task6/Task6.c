//Задача 6. Отворете и прочетете съдържанието от файл с fscanf.

#include <stdio.h>

#define SIZE 30

int main()
{
    FILE* fp = NULL;
    char strOutput[SIZE] = { 0 };

    if( ( fp = fopen("Task6.txt", "r+") ) == NULL)
    {
        printf("Can not open the file for input and output");
        return -1;
    }

    fscanf(fp, "%[^\n]", strOutput);
    printf("The file contains: %s", strOutput);

    fclose(fp);

    return 0;
}