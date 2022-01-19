/*
Задача 7. Използвайте функцията getchar(), с която въвеждате текст от
клавиатурата, докато не подадете ЕОF(Ctrl+D). Текстът да отпечатва
само входни редове, които са по дълги от 80 символа.
*/
#include <stdio.h>

int main()
{
    char cChar = 0;
    char sStr[120] = { 0 };
    int iCounter = 0, i = 0;
    
    while(cChar != EOF)
    {
        cChar = getchar();
        iCounter++;
        sStr[i] = cChar;
        i++;
    }

    if(iCounter >= 80)
    {
        printf("%s", sStr);
    }

    return 0;
}