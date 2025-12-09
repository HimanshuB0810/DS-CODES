#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};
struct node*front=0,*rear=0,*newnode,*temp;

void enqueue(int x)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;

    if(front==0 && rear==0)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}

void display()
{
    temp=front;
    if(front==0 && rear==0)
    {
        printf("Empty");
    }
    else
    {
        while(temp!=0)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}

void dequeue()
{
    temp=front;
    if(front==0 && rear==0)
    {
        printf("Empty");
    }
    else
    {
        printf("Dequeued element: %d\n",front->data);
        front=front->next;
        free(temp);
    }

}

void peek()
{
    temp=front;
    if(front==0 && rear==0)
    {
        printf("Empty");
    }
    else
    {
        printf("rear element: %d\n",front->data);
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    peek();
    dequeue();
    display();
}