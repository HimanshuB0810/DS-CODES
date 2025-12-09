#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};
struct node*newnode,*top=0,*temp; // initially top is 0 [data,0]
void push(int x) 
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=top;
    top=newnode;
}

void display()
{
    temp=top;
    if(top==0)
    {
        printf("List is Empty");
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

void peek()
{
    if(top==0)
    {
        printf("List is Empty");
    }
    else
    {
        printf("Top element of the stack is: %d\n",top->data);
    }
}

void pop()
{
    temp=top;
    if(top==0)
    {
        printf("List is Empty");
    }
    else
    {
        printf("Element poped is: %d\n",top->data);
        top=top->next;
        free(temp);
    }
}

int main()
{
    push(20);
    push(40);
    push(50);
    peek();
    display();
    pop();
    display();
}