#include<stdio.h>
# define N 5
int queue[N];
int front=-1;
int rear=-1;

void enqueue(int x)
{
    if(rear==N-1)
    {
        printf("Overflow!");
    }
    else if(front==-1 && rear==-1)
    {
        front++;
        rear++;
        queue[rear]=x;
    }
    else
    {
        rear++;
        queue[rear]=x;
    }
}

void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Underflow!");
    }
    else if(front==rear)
    {
        printf("Element Dequeue: %d",queue[front]);
        front=-1;
        rear=-1;
    }
    else
    {
        printf("Element Dequeue: %d",queue[front]);
        front++;
    }
}

void display()
{
    for(int i=front;i<=rear;i++)
    {
        printf("%d\t",queue[i]);
    }
}

void main()
{
    enqueue(550);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    display();
}

