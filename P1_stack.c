#include <stdio.h>

#define SIZE 2

int stack[SIZE];
int top = -1;

void push()
{
    int x;
    if (top == SIZE - 1)
    {
        printf("Stack Overflow! Cannot push.\n");
    }
    else
    {
        printf("Enter element to push: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
        printf("Element pushed successfully.\n");
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! Nothing to pop.\n");
    }
    else
    {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Top element: %d\n", stack[top]);
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements: ");
        for (i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
