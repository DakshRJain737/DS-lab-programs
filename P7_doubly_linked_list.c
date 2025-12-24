#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head = NULL;

struct node *create(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void insert_end(int val)
{
    struct node *temp, *newnode;
    if (head == NULL)
    {
        head = create(val);
        return;
    }
    newnode = create(val);
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    return;
}

void insert_left(int val, int key)
{
    struct node *newnode, *temp;

    if (head == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }
    temp = head;
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Key Not found!\n");
        return;
    }
    newnode = create(val);
    newnode->next = temp;
    newnode->prev = temp->prev;

    if (temp->prev != NULL)
    {
        temp->prev->next = newnode;
    }
    else
    {
        head = newnode;
    }
    temp->prev = newnode;
}

void delete_key(int key)
{
    struct node *temp1;
    if (head == NULL)
    {
        printf("Linked List is empty!\n");
        return;
    }

    else if (head->data == key)
    {
        temp1 = head;
        head = head->next;
        head->prev = NULL;
        free(temp1);
    }

    else
    {
        temp1 = head;
        while (temp1 != NULL && temp1->data != key)
        {
            temp1 = temp1->next;
        }
        temp1->prev->next = temp1->next;
        if (temp1->next != NULL)
        {
            temp1->next->prev = temp1->prev;
        }
        free(temp1);
    }
}

void display()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("Linked list is Empty!\n");
        return;
    }
    temp = head;
    printf("Doubly Linked list elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, val, key;

    while (1)
    {
        printf("1. Insert end\n2. Insert to left of key\n3. Delete Key\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            insert_end(val);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &val);
            printf("Enter Key: ");
            scanf("%d", &key);
            insert_left(val, key);
            break;

        case 3:
            printf("Enter Key: ");
            scanf("%d", &key);
            delete_key(key);
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Invalid choice! Try again.\n");
            break;
        }
    }

    return 0;
}