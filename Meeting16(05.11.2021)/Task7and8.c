// Задача 7. Направете функция struct point makepoint(int x, int y), която
// създава две точки. Използвайте malloc().

// Задача 8. Направете структура struct rect, която съдържа в себе си две
// точки. Създайте обект от тип тази структура наречен screen. Използвайте
// функцията makepoint за да зададете начална точка на екрана (0, 0) и крайна
// точка (15, 15). Запълнете пространството между тях с тирета.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct point
{
    int x;
    int y;
};

struct rectangle{
    struct point *a;
    struct point *b;
};

struct point *makepoint(int x, int y);
void drawLines(struct point *beg, struct point *end, int size);

int main()
{
    struct rectangle *screen = (struct rectangle*)malloc(sizeof(struct rectangle));
    int size = 15;

    screen->a = makepoint(0, 0);
    screen->b = makepoint(size, size);

    drawLines(screen->a, screen->b, size);

    free(screen->a);
    free(screen->b);
    free(screen);

    return 0;
}

struct point *makepoint(int x, int y)
{
    struct point *temp = (struct point*)malloc(sizeof(struct point));

    temp->x = x;
    temp->y = y;

    return temp;
}

void drawLines(struct point *beg, struct point *end, int size)
{
    for(int i = 0; i <= size; i++)
    {
        beg->x = i;

        for(int j = 0; j <= size; j++)
        {
            beg->y = j;

            if( (beg->x != 0 || beg->y != 0) && (beg->x != end->x || beg->y != end->y) )
            {
                putchar('-');
            }
            else
            {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}