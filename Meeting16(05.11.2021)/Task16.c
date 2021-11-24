#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 128

struct node{
    int m_Num;
    
    struct node *next;
};

void insert(struct node** head);
void deleteLast(struct node* head);
void delete(struct node* head);
void display(struct node* head);

int main()
{
    struct node* head = NULL;
    int iCount = 0;

    printf("Enter the amount of numbers in the list: ");
    scanf("%d", &iCount);

    for(int i = 0; i < iCount; i++)
    {
        insert(&head);
    }

    display(head);

    deleteLast(head);

    display(head);

    delete(head);

    return 0;
}

void insert(struct node** head)
{
    int iNum = 0;
    struct node* new = (struct node*)malloc(sizeof(struct node));
    struct node* curr = NULL;

    printf("\nEnter a number: ");
    scanf("%d", &iNum);

    new->m_Num = iNum;
    new->next = NULL;

    if(*head == NULL)
    {
        *head = new;
    }
    else
    {
        curr = *head;

        while(curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = new;
    }
}

void deleteLast(struct node* head)
{
    struct node* list = head;
    int iNum = 0;

    printf("Deleting the last number...\n");

    while(list->next->next != NULL)
    {
        list = list->next;
    }

    free(list->next);
    list->next = NULL;
}

void display(struct node* head)
{
    struct node* curr = head;

    while(curr != NULL)
    {
        printf("%d\n", curr->m_Num);
        curr = curr->next;
    }
}

void delete(struct node* head)
{
    struct node* curr;

    while(head)
    {
        curr = head->next;
        free(head);
        head = curr;
    }
}