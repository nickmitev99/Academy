// Задача 7. Напишете заглавен файл с декларации на функции и 
// сложете гардове. Този начин намалява времето за компилиране на 
// големи проекти.

#include <stdio.h>
#include "Task7.h"
#include "Task7.h"

int main()
{
    print("Message");

    return 0;
}

void print(char *msg)
{
    while(*msg)
    {
        putchar(*msg);
        msg++;
    }
}