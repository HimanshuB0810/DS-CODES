#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
    struct node*prev;
};
struct node*head=NULL,*temp,*newnode,*tail;

struct node* getnode()
{
    newnode=(struct node*)malloc(sizeof( struct node));
    printf("Enter Data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

void display()
{
    temp=head;
    while (temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

int main()
{
    int choice=1;
    while (choice)
    {
        printf("Do you want to add a new node? 0 or NO, 1 for YES: ");
        scanf("%d",&choice);
        if(choice==0)
        {
            break;
        }
        if(head==NULL)
        {
            newnode=getnode();
            head=tail=newnode;
        }
        else
        {
            newnode=getnode();
            tail->next=newnode;
            newnode->prev=tail;
            tail=tail->next;
        }
    }
    display();
    return 0;
}