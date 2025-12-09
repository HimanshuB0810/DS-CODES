#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};
struct node*head=NULL,*temp=NULL,*newnode;
struct node *getnode()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    return newnode;
}

void deletion_at_start()
{
    if(head==NULL)
    {
        printf("The list is empty");
        return;
    }
    temp=head;
    head=temp->next;
    free(temp);
}

void deletion_at_end()
{
    struct node*prevnode;
    if (head == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    temp=head;
    while(temp->next!=NULL)
    {
        prevnode=temp;
        temp=temp->next;
    }
    if(head==NULL)
    {
        head=0;
    }
    else
    {
        prevnode->next=NULL;
    }
    free(temp);
}

void deletion_at_pos()
{
    int i=1,pos;
    struct node*nextnode;
    printf("Enter position: ");
    scanf("%d",&pos);
    temp=head;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;   
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);
}

void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    int choice=1,count=0;
    while(choice)
    {
        printf("Do you want to add newnode? (0 for NO, 1 for YES)");
        scanf("%d",&choice);
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
            count++;
        }
    }
    display();
    deletion_at_start();
    display();
    deletion_at_end();
    display();
    deletion_at_pos();
    display();
    return 0;
}

