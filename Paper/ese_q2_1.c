// Coffee Database

#include<stdio.h>
#include<stdlib.h>
struct beverage{
    char name[50];
    int id;
    float price;
    struct beverage *next;
};
struct beverage *temp, *newnode, *head=NULL;
struct beverage *getnode()
{
    newnode=(struct beverage*)malloc(sizeof(struct beverage));
    printf("Enter Name of Beverage: ");
    scanf("%s",newnode->name);
    printf("Enter ID: ");
    scanf("%d",&newnode->id);
    printf("Enter Price: ");
    scanf("%f",&newnode->price);
    newnode->next=NULL;
    return newnode;
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("Name of the Beverage: %s\n",temp->name);
        temp=temp->next;
    }
}

void add_beverage_at_end()
{   temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    newnode=getnode();
    temp->next=newnode;
}

void max_price()
{
    struct beverage* maxnode;
    maxnode=head;
    temp=head;
    while (temp!=NULL)
    {
        if(maxnode->price<temp->price)
        {
            maxnode=temp;
        }
        temp=temp->next;
    }
    printf("Name of the Beverage having maximum price is : %s",maxnode->name);    
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
        printf("Do you want to continue? 1 for YES and 0 for NO! ");
        scanf("%d",&choice);
    }
    display();
    // add_beverage_at_end();
    // display();
    max_price();

}