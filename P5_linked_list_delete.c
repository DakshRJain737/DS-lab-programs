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

void insert_begin(int val)
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

void delete_begin()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("Linked List is Empty");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
}

void delete_last()
{
    struct node *temp1, *temp2;
    if (head == NULL)
    {
        printf("Linked List is empty");
        return;
    }

    temp2 = temp1 = head;

    while (temp1->next != NULL)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    temp2->next = NULL;
    free(temp1);

    if (temp1 == head)
    {
        head = NULL;
    }
}

void delete_element(int element)
{
    struct node *temp1, *temp2;
    if (head == NULL)
    {
        printf("Linked List is Empty");
        return;
    }
    else if (head->data == element)
    {
        temp1 = head;
        head = head->next;
        free(temp1);
        return;
    }
    else
    {
        temp2 = temp1 = head;

        while (temp1->data != element)
        {
            if (temp1->next == NULL)
            {
                printf("Cannot delete non existing element");
                return;
            }
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = temp1->next;
        free(temp1);
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
    int choice, val, element;

    while (1)
    {
        printf("\n1. Insert an Element\n2. Delete at Beginning\n3. Delete at End\n4. Delete an element\n5. Display\n6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Value: ");
            scanf("%d", &val);
            insert_begin(val);
            break;
        case 2:
            delete_begin();
            break;
        case 3:
            delete_last();
            break;
        case 4:
            printf("Enter Element: ");
            scanf("%d", &element);
            delete_element(element);
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Enter Valid Choice\n");
            break;
        }
    }
}