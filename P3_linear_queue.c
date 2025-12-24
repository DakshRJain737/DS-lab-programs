#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 3

int queue_array[MAX_SIZE];
int front = -1;
int rear = -1;

void insert() {
    int elem;
    if (rear == MAX_SIZE-1) {
        printf("\nQueue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    printf("\nEnter element: ");
    scanf("%d", &elem);
    rear = rear + 1;
    queue_array[rear] = elem;
}

void delete() {
    int elem;
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow\n");
        return;
    }

    printf("\nDeleted Element: %d\n", queue_array[front]);
    front += 1;
}

void display() {
    if (front == -1 || front >= rear) {
        printf("\nQueue is Empty!\n");
        return;
    }
    printf("\nQueue is: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue_array[i]);
    }
    printf("\n");
}

void main() {
    int choice;
    while (1) {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nEnter Valid Choice\n");
        }
        printf("\n\n");
    }
}