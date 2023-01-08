#include <stdio.h> // printf(), scanf(), NULL
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *HEAD = NULL;

struct node *createNode()
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    return n;
}

// Insert node at the end of List
void insertNode()
{
    struct node *temp, *t;
    temp = createNode();

    printf("Enter a number: ");
    scanf("%d", &temp->data);

    temp->link = NULL;

    if (HEAD == NULL)
    {
        HEAD = temp;
    }
    else
    {
        t = HEAD;

        while (t->link != NULL)
        {
            t = t->link;
        }
        t->link = temp;
    }
}

// Delete the first Node
void deleteNode()
{
    struct node *r;

    if (HEAD == NULL)
        printf("List is empty");
    else
    {
        r = HEAD;
        HEAD = HEAD->link;
        free(r);
    }
}

// Traverse the Linked List
void viewList()
{
    struct node *t;

    if (HEAD == NULL)
        printf("List is empty");
    else
    {
        t = HEAD;
        while (t != NULL)
        {
            printf("%d\n", t->data);
            t = t->link;
        }
    }
}

int menu()
{
    int choice;

    printf("\n1. Insert Node: ");
    printf("\n2. Delete Node: ");
    printf("\n3. View List: ");
    printf("\n4. Exit: ");
    printf("\nEnter your Choice: ");
    scanf("%d", &choice);

    return choice;
}

int main()
{
    // int choice;

    while (1)
    {
        switch (menu())
        {
        case 1:
            insertNode();
            break;
        case 2:
            deleteNode();
            break;
        case 3:
            viewList();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Choice");
        }
    }
    return 0;
}