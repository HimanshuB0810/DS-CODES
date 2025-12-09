#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
    struct node*prev;
};
struct node*newnode,*head,*temp;
struct node*getnode()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}

void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",newnode->data);
        temp=temp->next;
    }
}

void main()
{
    getnode();
    getnode();
    getnode();
    display();
}

