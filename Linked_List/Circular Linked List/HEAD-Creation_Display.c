#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};

struct node*head,*temp,*newnode;

struct node*getnode()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory Allocation Failed");
        return NULL;
    }
    else
    {
        printf("Enter Data: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        return newnode;
    }
}
void display()
{
    if(head==NULL)
    {
        printf("List is Empty!");
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);

    }
}
int main()
{
    int choice=1,count=0;
    while(choice)
    {
        printf("Do you want to add newnode? 0 for NO , 1 for YES ");
        scanf("%d",&choice);
        if(choice==0)
        {
            break;
        }
        if(head==NULL)
        {
            head=getnode();
            temp=head;
        }
        else
        {
            newnode=getnode();
            temp->next=newnode;
            temp=newnode;
        }
        temp->next=head;
    }
    display();
    return 0;
}

