// "Write a C program to implement a singly linked list that supports insertion at the start ,
// insertion at the end, insertion after a specific key, and display of the list."

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};

struct node* getnode()
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory Allocation falied");
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

void insert_at_start(struct node**head);
void insert_at_end(struct node**head);
void insert_at_btw(struct node**head);
void display(struct node*head);

int main()
{
    struct node*head=NULL;
    int choice=0;
    while(1)
    {
        printf("1. Insert node at the start\n");
        printf("2. Insert node at the end\n");
        printf("3. Insert node at between\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            insert_at_start(&head);
            break;

            case 2:
            insert_at_end(&head);
            break;

            case 3:
            insert_at_btw(&head);
            break;

            case 4:
            display(head);
            break;

            case 5:
            exit(0);

            default:
            printf("Invalid number passed");
        }
    }
    return 0;
}

void insert_at_start(struct node**head)
{
    struct node*newnode;
    newnode=getnode();
    newnode->next=*head;
    *head=newnode;
}

void insert_at_end(struct node**head)
{
    struct node*newnode,*temp;
    newnode=getnode();
    temp=*head;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next=newnode;

}

void insert_at_btw(struct node**head)
{
    int i=1,pos,count=0;
    struct node*temp;
    temp=*head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("Enter Position after which you want to insert the node");
    scanf("%d",&pos);

    if(pos>count)
    {
        printf("Invalid Position");
    }
    else
    {
        temp=*head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        struct node*newnode;
        newnode=getnode();
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

void display(struct node*head)
{
    if(head==0)
    {
        printf("List is empty!\n");
    }
    struct node*temp;
    temp=head;
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}