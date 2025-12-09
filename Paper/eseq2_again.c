#include<stdio.h>
#include<stdlib.h>

struct seat
{
    int seat_number;
    int id;
    char name[50];
    struct seat* next;
};
struct seat* newnode, *head, *temp;
struct seat* getnode()
{
 newnode=(struct seat*)malloc(sizeof(struct seat));
 printf("enter seat number: ");
 scanf("%d",&newnode->seat_number);
 printf("Enter id: ");
 scanf("%d",&newnode->id);
 printf("enter name: ");
 scanf("%s",newnode->name);
 newnode->next=NULL;
 return newnode;
}

void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("Name: %s\n",temp->name);
        printf("ID: %d\n",temp->id);
        printf("Seat Number: %d\n",temp->seat_number);
        temp=temp->next;
    }
}

void add_at_end()
{
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    newnode=getnode();
    temp->next=newnode;
}

void minSeat()
{
    struct seat* minnode;
    minnode=head;
    temp=head;
    while(temp!=NULL)
    {
        if(minnode->seat_number>temp->seat_number)
        {
            minnode=temp;
        }
        temp=temp->next;
    }
    printf("Min: %s",minnode->name);
}

int main()
{
    int choice=1;
    while(choice)
    {
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
        printf("0 for no, 1 for yes");
        scanf("%d",&choice);
    }
    display();
    add_at_end();
    display();
    minSeat();
}