// Задача 9. Дефинирайте структура, в която има член указател към самата
// структура. Използвайте тази структура, за да дефинирате две променливи,
// които се указват една друга.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 128

struct arrow{
    char *name;
    struct arrow *otherArrow;
};

void setArrow(struct arrow *arrow, struct arrow *pointed_obj);
void printArrow(struct arrow *arrow);

int main()
{
    struct arrow *a1 = NULL, *a2 = NULL;

    a1 = (struct arrow*)malloc(sizeof(struct arrow));
    a2 = (struct arrow*)malloc(sizeof(struct arrow));

    setArrow(a1, a2);
    setArrow(a2, a1);

    printArrow(a1);
    printArrow(a2);

    free(a1->name);
    free(a2->name);

    free(a1);
    free(a2);
}

void setArrow(struct arrow *arrow, struct arrow *pointed_obj)
{
    int i = 0;
    char name[MAX];

    printf("Enter the name of the arrow: ");
    scanf("%s", name);

    arrow->name = malloc(strlen(name));
    strcpy(arrow->name, name);

    arrow->otherArrow = pointed_obj;
}

void printArrow(struct arrow *arrow)
{
    printf("The %s arrow points to the %s arrow\n", arrow->name, arrow->otherArrow->name);
}