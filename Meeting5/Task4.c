/* Задача 11. Ако имаме символен низ от символа char str[] = “Hello”;
копирайте всеки един от неговите символи в низ , който да изглежда
огледален на него . Ето така char rts [] = oll е H ”; и принтирайте
резултата
*/

#include<stdio.h>
#include<string.h>

void reverseString(unsigned char* array, unsigned char* reverse, int size);

int main()
{
    unsigned char aArray[] = "Hi";
    int iSize = strlen(aArray);
    unsigned char aReversed[sizeof(aArray)];

    reverseString(aArray, aReversed, iSize);

    printf("%s\n", aArray);
    printf("%s\n", aReversed);

    return 0;
}


void reverseString(unsigned char* array, unsigned char* reverse, int size)
{
    int i = 0;

    while(i < (size-1))
    {
        array++;
        i++;
    }

    while(size-- >= 0)
    {
        *reverse++ = *array--;

        if(size == 0)
        {
            reverse[size] = '\0';
        }
    }
}