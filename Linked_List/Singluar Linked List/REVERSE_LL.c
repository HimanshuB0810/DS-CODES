#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};
struct node*head=NULL,*temp,*newnode;
void reverse()
{
    struct node*prev_node,*curr_node,*next_node;
    prev_node=0;
    curr_node=next_node=head;
    while(next_node!=0)
    {
        next_node=next_node->next;
        curr_node->next=prev_node;
        prev_node=curr_node;
        curr_node=next_node;
    }
    head=prev_node;
    
}

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
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
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
    }
    display();
    reverse();
    display();
    return 0;
}