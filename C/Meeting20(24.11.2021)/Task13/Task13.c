// Задача 13. Напишете програма, която печата съдържанието на файл
// в обратен ред.Използвайте fseek, за да отидете накрая на файла.
// Използвайте ftell функцията, за да намерите позицията на указателя
// във файла. Принтирайте на екрана файла, обърнат в обратен ред.

#include <stdio.h>

#define SIZE 100

int main()
{
    FILE* fp = NULL, *fp2;
    char cChar = 0;
    char strOutput[SIZE] = { 0 };
    long int iCharCount = 0;

    if( ( fp = fopen("Task13.txt", "r+") ) == NULL)
    {
        printf("Can not open the file for input and output");
        return -1;
    }

    fseek(fp, -1, SEEK_END);
    iCharCount = ftell(fp);

    for(int i = iCharCount; i >= 0; i--)
    {
        fseek(fp, i, SEEK_SET);
        cChar = fgetc(fp);

        if(cChar == '\n')
        {
            fseek(fp, i-1, SEEK_SET);
            i--;
        }

        putchar(cChar);
    }

    fclose(fp);

    return 0;
}