#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;
struct node *front = NULL, *rear = NULL;

void push(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    struct node *temp;
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }
    temp = top;
    printf("Popped element: %d\n", temp->data);
    top = top->next;
    free(temp);
}

void peek_stack()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", top->data);
}

void display_stack()
{
    struct node *temp = top;
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void enqueue(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Queue Overflow\n");
        return;
    }
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    struct node *temp;
    if (front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }
    temp = front;
    printf("Dequeued element: %d\n", temp->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void pee_queue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", front->data);
}

void display_queue()
{
    struct node *temp = front;
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, value, subChoice;

    while (1)
    {
        printf("\n1. Push Stack\n");
        printf("2. Pop Stack\n");
        printf("3. Peek Stack\n");
        printf("4. Display Stack\n");
        printf("5. Enqueue Queue\n");
        printf("6. Dequeue Queue\n");
        printf("7. Peek Queue\n");
        printf("8. Display Queue\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek_stack();
            break;
        case 4:
            display_stack();
            break;

        case 5:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 6:
            dequeue();
            break;
        case 7:
            pee_queue();
            break;
        case 8:
            display_queue();
            break;
        }
    }
    return 0;
}
