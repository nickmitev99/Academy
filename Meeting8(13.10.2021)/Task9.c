/*
Задача 9. Използвайте функцията getchar(), с която въвеждате текст от
клавиатурата, докато не подадете ЕОF(Ctrl+D). Текстът се принтира с
putchar(), като преобразува главните букви в малки.
*/

#include <stdio.h>

int main()
{
    char cChar = 0;
    
    while(cChar != EOF)
    {
        cChar = getchar();

        if( (cChar >= 'A') && (cChar <= 'Z') )
        {
            cChar += 32;
        }
        
        putchar(cChar);
    }

    return 0;
}