#include<stdio.h>
#include<stdlib.h>
struct seat{
    int number;
    int ID;
    char name[20];
    struct seat*next;
};
struct seat *newnode, *head=NULL, *temp;
struct seat*getnode()
{
    newnode=(struct seat*)malloc(sizeof(struct seat));
    printf("Enter Name: ");
    scanf("%s",newnode->name);
    printf("Enter ID: ");
    scanf("%d",&newnode->ID);
    printf("Enter Seat Number: ");
    scanf("%d",&newnode->number);
    newnode->next=NULL;
    return newnode;
}

void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("Name: %s\n",temp->name);
        printf("ID: %d\n",temp->ID);
        printf("Seat Number: %d\n",temp->number);
        temp=temp->next;
    }
}

void add_booking_at_start()
{
    newnode=getnode();
    newnode->next=head;
    head=newnode;
}

void smallest_seat_number()
{
    struct seat* minnode;
    minnode=head;
    temp=head;
    while(temp!=NULL)
    {
        if(minnode->number>temp->number)
        {
            minnode=temp;
        }
        temp=temp->next;
    }
    printf("Details of the Earliest Seat Number\n");
    printf("Name: %s\n",minnode->name);
    printf("Id: %d\n",minnode->ID);
    printf("Seat Number: %d\n",minnode->number);
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
        printf("1 for YES, 0 for NO ");
        scanf("%d",&choice);
    }
    display();
    // add_booking_at_start();
    // display();
    smallest_seat_number();
}