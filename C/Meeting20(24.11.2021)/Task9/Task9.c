// Задача 9. Направете същото ползвайки fgetpos().
// int fgetpos(FILE *pfile, fpos_t *position);

#include <stdio.h>

int main()
{
    FILE* fp = NULL;
    fpos_t fPosition = 0;

    if( ( fp = fopen("Task9.txt", "r+") ) == NULL)
    {
        printf("Can not open the file for input and output");
        return -1;
    }

    fseek(fp, 0, SEEK_SET);
    fgetpos(fp, &fPosition);
    printf("Position of the first character of the file is: %d\n", fPosition);

    fseek(fp, 0, SEEK_END);
    fgetpos(fp, &fPosition);

    printf("Position of the last character of the file is: %d\n", fPosition);

    fseek(fp, -7, SEEK_CUR);
    fgetpos(fp, &fPosition);

    printf("Current position -7 characters of the file is: %d\n", fPosition);

    fclose(fp);

    return 0;
}