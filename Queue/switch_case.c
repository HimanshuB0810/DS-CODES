#include<stdio.h>
#include<stdlib.h>

#define N 5
int queue[N];
int front=-1;
int rear=-1;

void main()
{
    int choice;
    while(1)
    {
        printf("Enter 1 for enqueue\n");
        printf("Enter 2 for dequeue\n");
        printf("Enter 3 for peek\n");
        printf("Enter 4 for display\n");
        printf("Enter 5 for exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            enqueue();
            break;

            case 2:
            dequeue();
            break;

            case 3:
            peek();
            break;

            case 4:
            display();
            break;

            case 5:
            exit(0);
            break;

            default:
            printf("Enter Valid choice");
        }
    }
}

void enqueue()
{
    int x;
    printf("Enter Data: ");
    scanf("%d",&x);
    if(rear==N-1)
    {
        printf("Overflow\n");
    }
    else if (front==-1 && rear==-1)
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
        printf("Underflow\n");
    }
    else if(front==rear)
    {
        printf("Element to be deleted is: %d\n",queue[front]);
        front=rear=-1;
    }
    else
    {
        printf("Element deleted is: %d\n",queue[front]);
        front++;
    }
}

void peek()
{
    if(front==-1 && rear==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("Element at front is: %d\n",queue[front]);
    }
}   

void display()
{
    int i;
    if(front==-1 && rear==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d\t",queue[i]);
        }
        printf("\n");
    }
}