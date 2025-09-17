#include<stdio.h>

int a[100];
int n, TOP= -1;

void push()
{
if (TOP == n - 1)
{
printf("Stack is full\n");
}
else
{
TOP++;
printf("Enter item: ");
scanf("%d", &a[TOP]);
}
}

void pop()
{
if (TOP==-1)
{
printf("Stack is empty\n");
}
else
{
printf("Popped item is: %d\n", a[TOP]);
TOP--;
}
}

void display()
{
int i;
if (TOP== -1 )
{
printf("Stack is empty\n");
}
else
{
printf("Elements are:\n");
for (i = TOP; i>=0; i--)
{
printf("%d\t", a[i]);
}
printf("\n");
}
}

void main()
{
int c;
printf("Enter Stack Size: ");
scanf("%d", &n);
do
{
printf("\n1.PUSH\n2.POP\n3. Display\n4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &c);
switch(c)
{
case 1:
push();
break;
case 2:
pop();
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
}
