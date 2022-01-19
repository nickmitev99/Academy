// Задача 3. Реализирайте условна компилация в зависимост от макрос DEBUG

#include <stdio.h>

#define DEBUG

int main()
{
    #ifdef DEBUG
        printf("Debug is defined!");

    #else
        printf("Debug isn't defined!");

    #endif

    return 0;
}