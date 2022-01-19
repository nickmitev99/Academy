// Задача 6. Напишете макрос с променлив брой параметри, който 
// извиква printf със префикс “TRACE: ”

#include <stdio.h>

#define PRINT(...)  printf("TRACE: "__VA_ARGS__)

int main()
{   
    PRINT("%s %d %d %d\n", "Example with ints", 1, 2 ,3);
    PRINT("%s %f %f %f\n", "Example with floats", 1.1, 2.2 ,3.3);
    PRINT("%s %s %s %s\n", "Example with strings", "Hello", "there" ,"friend!");
    PRINT("%s %d %f %c %s\n", "Mixed examples", 34, 502.346, 'A', "String");

    return 0;
}