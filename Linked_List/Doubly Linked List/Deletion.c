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
    printf("\n");
}


void del_from_start()
{
    if(head==NULL)
    {
        printf("List is Empty!");
    }
    else
    {
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
}

void del_from_end()
{
    if(tail==NULL)
    {
        printf("List is Empty!");
    }
    else
    {
        temp=tail;
        tail->prev->next=NULL;
        tail=temp->prev;
        free(temp);
    }
}

void del_from_position()
{
    int pos,i=1;
    printf("Enter Position: ");
    scanf("%d",&pos);
    temp=head;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
}