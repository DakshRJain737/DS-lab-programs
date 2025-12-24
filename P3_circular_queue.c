#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 3

int cir_queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() {
    if ((front == rear + 1) || ((front == 0) && (rear == MAX_SIZE - 1))) return 1;
    return 0;
}

int isEmpty() {
    if (front == -1) return 1;
    return 0;
}

void enQueue(int elem) {
    if(isFull()) {
        printf("\nQueue is Full\n");
        return;
    }

    if (front == -1) front = 0;
    rear = (rear + 1) % MAX_SIZE;
    cir_queue[rear] = elem;
    printf("\nInserted Element: %d\n", elem);
}

int deQueue() {
    int elem;
    if (isEmpty()) {
        printf("\nQueue is Empty\n");
        return -1;
    }

    elem = cir_queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front = (front + 1) % MAX_SIZE;
    }

    printf("\nDeleted Element: %d\n", elem);
    return elem;
}

void display() {
    int i;
    if (isEmpty()) {
        printf("\nQueue is Empty\n");
        return;
    }

    printf("\nQueue is: ");
    for (i = front; i != rear; i = (i+1)%MAX_SIZE) {
        printf("%d ", cir_queue[i]);
    }

    printf("%d\n", cir_queue[i]);
}

void main() {
    int choice, val, del;
    while (1) {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("\nEnter element: ");
                scanf("%d", &val);
                enQueue(val);
                break;
            case 2:
                del = deQueue();
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