#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 128

struct node{
    int m_Num;
    
    struct node *next;
};

void insert(struct node** head);
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

    delete(head);

    return 0;
}

void insert(struct node** head)
{
    int iNum = 0;
    struct node* new = (struct node*)malloc(sizeof(struct node));
    struct node* curr = NULL;

    printf("Enter the amount of numbers in the list: ");
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

void display(struct node* head)
{
    if(head != NULL)
    {
        display(head->next);
        printf("%d\n", head->m_Num);
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