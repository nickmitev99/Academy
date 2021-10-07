/*Задача8 *. Напишете програма , която пресмята колко символа има в един
низ преди края на низа , обозначен със символа 0’. Как трябва да изглежда
програмата
1.
Декларираме и инициализираме един низ char s[ ] = “Hi”;
2.
Декларираме и инициализираме променлива i , която ще увеличаваме
всеки път , когато искаме да видим следващия символ от низа “
3.
Принтираме съответната буква от низа printf (“%c”, i
4.
Принтирайте броя на буквите в низа*/

#include <stdio.h>

void stringSize(unsigned char* array, int size);

int main()
{
    unsigned char aArray[] = "Hi";
    int iSize = sizeof(aArray);

    stringSize(aArray, iSize);

    return 0;
}


void stringSize(unsigned char* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%c", array[i]);

        if(array[i] == '\0')
        {
            size -= 1;
        }
    }
    printf("\n%d", size);
}