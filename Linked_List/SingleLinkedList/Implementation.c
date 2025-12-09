#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};

struct node *temp, *newnode, *head;

struct node*getnode()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Memory Allocation Failed\n");
        return NULL;
    }
    else
    {
        printf("Enter Data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        return newnode;
    }
}

void display()
{
    temp=head;
    if(temp==NULL)
    {
        printf("The Linked list is empty");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}

int main()
{
    int choice=1,count=0;
    while(choice)
    {
        printf("Do you want to add another node? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);
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
            count++;
        }
    }
    display();
    
}