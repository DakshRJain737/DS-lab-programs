#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

struct node *create(int val)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

void insertion_begin(int val)
{
    struct node *temp;
    temp = create(val);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

void insertion_last(int val)
{
    struct node *nextnode, *temp;
    nextnode = create(val);

    if (head == NULL)
    {
        head = nextnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nextnode;
    }
}

void insertion_pos(int val, int pos)
{
    struct node *nextnode, *temp;
    nextnode = create(val);

    if (head == NULL)
    {
        if (pos == 0)
        {
            head = nextnode;
        }
        else
        {
            printf("Linked-List is Empty\nCannot insert at pos %d\n", pos);
        }
    }
    else
    {
        temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp->next == NULL)
            {
                printf("Cannot Insert at pos %d\n", pos);
                return;
            }
            temp = temp->next;
        }
        nextnode->next = temp->next;
        temp->next = nextnode;
    }
}

void display()
{
    struct node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("Linked-list is Empty\n");
    }
    else
    {
        printf("Linked-list Elements: ");
        while (temp->next != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
    }
    printf("\n");
}

void main()
{
    int choice, val, pos;

    while (1)
    {
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Pos\n4. Display\n5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Value: ");
            scanf("%d", &val);
            insertion_begin(val);
            break;
        case 2:
            printf("Enter Value: ");
            scanf("%d", &val);
            insertion_last(val);
            break;
        case 3:
            printf("Enter Value and Position: ");
            scanf("%d %d", &val, &pos);
            insertion_pos(val, pos);
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Enter Valid Choice\n");
            break;
        }
    }
}