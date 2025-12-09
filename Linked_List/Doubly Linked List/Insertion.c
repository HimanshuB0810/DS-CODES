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

int get_length()
{
    temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
void insert_at_start()
{
    newnode=getnode();
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}

void insert_at_end()
{
    newnode=getnode();
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
}

void insert_at_position()
{
    int pos,i=1,count;
    count=get_length();
    printf("Enter Position: ");
    scanf("%d",&pos);
    if(pos<1 || pos>count)
    {
        printf("Invalid Position ");
    }
    else if (pos==1)
    {
        insert_at_start();
    }
    else
    {
        newnode=getnode();
        temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->next->prev=newnode;
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
    insert_at_start();
    display();
    insert_at_end();
    display();
    insert_at_position();
    display();
    return 0;
}