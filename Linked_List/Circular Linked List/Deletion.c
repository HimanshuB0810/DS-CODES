#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};

struct node*tail,*temp;

void delete_from_start()
{
    temp=tail->next;
    if(tail==NULL)
    {
        printf("List is Empty! ");
    }
    else if(temp->next=temp)
    {
        tail=NULL;
        free(temp);
    }
    else
    {
        tail->next=temp->next;
        free(temp);
    }
}

void delete_from_end()
{
    struct node*current,*previous;
    current=tail->next;
    if(tail=NULL)
    {
        printf("List is empty");
    }
    else if(current->next=current)
    {
        tail=NULL;
        free(current);
    }
    else
    {
        while(current->next!=tail->next)
        {
            previous=current;
            current=current->next;
        }
        previous->next=tail->next;
        tail=previous;
        free(current);
    }
}

int get_length()
{
    int count=0;
    struct node*start;
    temp=tail->next;
    start=temp;
    count=1;
    temp=temp->next;
    while(temp!=start)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

void delete_from_position()
{
    struct node*current,*nextnode;
    int pos,i=1;
    printf("Enter Position: ");
    scanf("%d",&pos);
    int l=get_length();
    if(pos<1||pos>l)
    {
        printf("Invalid Position");
    }
    else if(pos==1)
    {
        delete_from_start();
    }
    else
    {
        while(i<pos-1)
        {
            current=current->next;
            i++;
        }
        nextnode=current->next;
        current->next=nextnode->next;
        free(nextnode);
    }
}