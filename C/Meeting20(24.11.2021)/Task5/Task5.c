// Задача 5. Напишете програма, която чете числа от един текстов файл и ги
// записва в друг текстов файл.

#include <stdio.h>

int main()
{
    FILE *fpRead = NULL, *fpWrite = NULL;
    int iNum = 0;

    if( ( fpRead = fopen("Task5_Read.txt", "r") ) == NULL)
    {
        printf("Can not open the file for reading!");
        return -1;
    }

    if( ( fpWrite = fopen("Task5_Write.txt", "w") ) == NULL)
    {
        printf("Can not open the file for writing!");
        return -2;
    }

    while(!feof(fpRead))
    {
        fscanf(fpRead, "%d", &iNum);
        fprintf(fpWrite, "%d ", iNum);
    }

    fclose(fpRead);
    fclose(fpWrite);

    return 0;
}