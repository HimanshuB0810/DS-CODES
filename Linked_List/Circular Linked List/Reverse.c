#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};
struct node*tail;
void reverse()
{
    struct node*current,*prev,*nextnode;
    current=tail->next;
    nextnode=current->next;

    if(tail==NULL)
    {
        printf("List is empty!");
    }
    else if(current->next=current)
    {
        tail==NULL;
        free(current);
    }
    else
    {
        while(current!=tail)
        {
            prev=current;
            current=nextnode;
            nextnode=current->next;
            current->next=prev;
        }
        nextnode->next=tail;
        tail=nextnode;
    }
}