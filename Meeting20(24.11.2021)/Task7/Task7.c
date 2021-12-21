// Задача 7. Напишете текст с форматиращ параметър, като използвате:
// int fprint(FILE* stream, const char *forma…);

#include <stdio.h>

#define SIZE 30

int main()
{
    FILE* fp = NULL;
    char strInput[SIZE] = { 0 };

    if( ( fp = fopen("Task7.txt", "w+") ) == NULL)
    {
        printf("Can not open the file for input and output");
        return -1;
    }

    printf("Enter a text: ");
    scanf("%[^\n]", strInput);

    fprintf(fp, "%s", strInput);

    fclose(fp);

    return 0;
}