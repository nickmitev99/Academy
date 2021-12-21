// Задача 11. Напишете програма, която да намери общия брой на
// редовете в текстови файл. Създайте файл, който съдържа няколко
// реда текст. Внимавайте къде се позиционирате файла. Отворете
// файла. Използвайте променлива, която да брои броя на редовете.

#include <stdio.h>
#include <string.h>

#define SIZE 100

int main()
{
    FILE* fp = NULL;
    char strBufferOutput[100] = { 0 };
    int iNewLineCount = 0;

    if( ( fp = fopen("Task11.txt", "r+") ) == NULL)
    {
        printf("Can not open the file for input and output");
        return -1;
    }

    fseek(fp, 0, SEEK_SET);

    while(fgets(strBufferOutput, SIZE, fp) != NULL)
    {
        int iBuffLenght = strlen(strBufferOutput) - 1;

        if(strBufferOutput[iBuffLenght] == '\n')
        {
            iNewLineCount++;
        }
    }

    printf("The file has %d lines", iNewLineCount+1);

    fclose(fp);

    return 0;
}