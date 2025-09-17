#include<stdio.h>

int a[100];
int n, front = -1, rear = -1;

void enqueue()
{
if (rear == n - 1)
{
printf("Queue is full\n");
}
else
{
if (front == -1)
{
front = 0;
}
rear++;
printf("Enter item: ");
scanf("%d", &a[rear]);
}
}

void dequeue()
{
if (front == -1 || front > rear)
{
printf("Queue is empty\n");
}
else
{
printf("Deleted item is: %d\n", a[front]);
front++;
if (front > rear) {
front = -1;
rear = -1;
}
}
}

void display()
{
int i;
if (front == -1 || front > rear)
{
printf("Queue is empty\n");
}
else
{
printf("Elements are:\n");
for (i = front; i <= rear; i++)
{
printf("%d\t", a[i]);
}
printf("\n");
}
}

int main()
{
int c;
printf("Enter Queue Size: ");
scanf("%d", &n);
do
{
printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &c);
switch(c)
{
case 1:
enqueue();
break;
case 2:
dequeue();
break;
case 3:
display();
break;
case 4:
break;
default:
printf("Invalid Choice\n");
}
} while(c != 4);
return 0;
}
