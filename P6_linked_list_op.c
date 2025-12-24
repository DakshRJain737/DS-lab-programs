#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Cannot Allocate Memory!\n");
        return NULL;
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct node *insert_begin(int data, struct node *head)
{
    struct node *temp = create(data);
    if (temp == NULL)
        return head;

    temp->next = head;
    return temp;
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked-list is Empty\n");
        return;
    }

    printf("Linked-list Elements: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

/* Correct reverse function */
struct node *reverse_list(struct node *head)
{
    struct node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

/* Bubble sort by swapping data */
struct node *sort_list(struct node *head)
{
    if (head == NULL)
        return head;

    int swapped;
    struct node *ptr1;
    struct node *lptr = NULL;

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    return head;
}

/* Concatenate two lists */
struct node *concatenate_list(struct node *head1, struct node *head2)
{
    if (head1 == NULL)
        return head2;

    struct node *temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

int main()
{
    int data;
    struct node *head1 = NULL, *head2 = NULL;

    printf("Enter Linked list 1 elements:");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &data);
        head1 = insert_begin(data, head1);
    }

    display(head1);
    printf("\n");

    printf("Enter Linked list 2 elements:");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &data);
        head2 = insert_begin(data, head2);
    }

    display(head2);

    printf("\n");

    head1 = reverse_list(head1);
    printf("Reversed List 1:\n");
    display(head1);

    printf("\n");

    head2 = sort_list(head2);
    printf("Sorted List 2:\n");
    display(head2);

    printf("\n");

    head1 = concatenate_list(head1, head2);
    printf("Concatenated Linked List:\n");
    display(head1);

    printf("\n\n\n\n");

    return 0;
}
