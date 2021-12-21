// Задача 15. Направете сериализация и десериализация на структурата в
// XML формат по показания в лекцията начин:
// typedef struct Person{
// char name[20];
// int age;
// char gender;
// }t_person;

#include <stdio.h>

static const char *FORMAT_PERSON_IN = "<name>%[^<>]</name>\n<age>%d</age>\n<gender>%c</gender>\n";
static const char *FORMAT_PERSON_OUT_XML = "<name>%s</name>\n<age>%d</age>\n<gender>%c</gender>\n";
static const char *FORMAT_PERSON_OUT_NOXML = "%s\n%d\n%c\n";


typedef struct Person{
    char name[20];
    int age;
    char gender;
}t_person;

int main(void)
{
    t_person m ={
        .name = "Nikolay",
        .age = 32,
        .gender = 'M'
    };

    t_person dm;
    FILE *fp;

    if( (fp = fopen("Task15.xml", "w+" ) ) == NULL)
    {
        return -1;
    }

    fprintf(fp, FORMAT_PERSON_OUT_XML, m.name, m.age, m.gender);
    fseek(fp, 0, SEEK_SET);

    fscanf(fp, FORMAT_PERSON_IN, dm.name, &dm.age, &dm.gender);

    printf("\nWith the xml format:\n");
    printf(FORMAT_PERSON_OUT_XML, dm.name, dm.age, dm.gender);

    printf("\nWithout the xml format:\n");
    printf(FORMAT_PERSON_OUT_NOXML, dm.name, dm.age, dm.gender);

    fclose(fp);
}