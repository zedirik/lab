#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1, size;

void push(int item) {
    if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
        printf("Deque is FULL\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = size - 1;
    } else {
        front--;
    }
    deque[front] = item;
}

void inject(int item) {
    if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
        printf("Deque is FULL\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == size - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = item;
}

void pop() {
    if (front == -1) {
        printf("Deque is EMPTY\n");
        return;
    }
    printf("Deleted %d\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == size - 1) {
        front = 0;
    } else {
        front++;
    }
}

void eject() {
    if (front == -1) {
        printf("Deque is EMPTY\n");
        return;
    }
    printf("Deleted %d\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = size - 1;
    } else {
        rear--;
    }
}

void display() {
    if (front == -1) {
        printf("Deque is EMPTY\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % size;
    }
    printf("\n");
}

int main() {
    int opt, item;
    printf("Enter size of Deque: ");
    scanf("%d", &size);

    do {
        printf("\n1.PUSH  2.POP  3.INJECT  4.EJECT  5.DISPLAY  6.EXIT\n");
        printf("Enter option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("Enter item: ");
                scanf("%d", &item);
                inject(item);
                break;
            case 4:
                eject();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (opt != 6);

    return 0;
}