// insert element as specific position in circular linked list

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node* tail,*temp,*newnode;

struct node* getnode()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    return newnode;
}

void insert_at_pos()
{
    int i=1,pos;
    printf("Enter position: ");
    scanf("%d",&pos);
    temp=tail->next;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    newnode=getnode();
    newnode->next=temp->next;
    temp->next=newnode;
}

void display()
{
    temp=tail->next;
    while(temp->next!=tail->next)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}

int main()
{
    int choice=1;
    while(choice)
    {
        if(tail==NULL)
        {
            tail=getnode();
            tail->next=tail;
        }
        else
        {
            newnode=getnode();
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        printf("1 for yes, 0 for No ");
        scanf("%d",&choice);
    }
    display();
    insert_at_pos();
    display();
}