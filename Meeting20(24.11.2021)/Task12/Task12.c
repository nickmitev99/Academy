// Задача 12. Напишете програма, която да обръща всички символи в
// текстов файл. Запишете резултата в друг временен файл. След това
// преименувайте новия файл с името на оригиналния файл и изтрийте
// временното име. Отпечатайте съдържанието на резултатния файл на
// стандартния изход с главни букви.

#include <stdio.h>
#include <string.h>

#define SIZE 100

int main()
{
    FILE* fp = NULL, *fp2;
    char cChar = 0;
    char strOutput[SIZE] = { 0 };
    long int iCharCount = 0;

    if( ( fp = fopen("Task12.txt", "r+") ) == NULL)
    {
        printf("Can not open the file for input and output");
        return -1;
    }

    if( ( fp2 = fopen("Temp.txt", "w+") ) == NULL)
    {
        printf("Can not open the file for input and output");
        return -1;
    }

    while(cChar != EOF)
    {
        cChar = fgetc(fp);
        static int i = 0;
        strOutput[i] = cChar;
        i++;
    }

    fseek(fp, -2, SEEK_END);
    iCharCount = ftell(fp);

    for(int i = iCharCount; i >= 0; i--)
    {
        cChar = strOutput[i];
        fputc(cChar, fp2);
    }

    fclose(fp);
    fclose(fp2);

    remove("Task12.txt");
    rename("Temp.txt", "Task12.txt");

    if( ( fp = fopen("Task12.txt", "r+") ) == NULL)
    {
        printf("Can not open the file for input and output");
        return -1;
    }

    printf("The file's new contents are: \n\n");
    fread(strOutput, strlen(strOutput) + 1, 1, fp);
    printf("%s", strOutput);

    fclose(fp);

    return 0;
}