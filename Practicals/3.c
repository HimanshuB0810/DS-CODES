// 3. Program based on singly linked list:
//  Maintain a record of coffee shop database implement
// following:
// i. Display the total sale of a day
// ii. Maximum and minimum bill of a day

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    char name[20];
    struct node* next;
};
struct node*head,*temp,*newnode;

struct node* getnode()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d",&newnode->data);
    printf("Enter Name: ");
    scanf("%s",&newnode->name);
    newnode->next=NULL;
    return newnode;
}

void total_sales()
{
    int total=0;
    temp=head;
    while(temp!=NULL)
    {
        total=total+temp->data;
        temp=temp->next;
    }
    printf("Total Sales: %d",total);
}

void max_min()
{
    struct node*max,*min;
    temp=head;
    max=head;
    min=head;

    while(temp!=NULL)
    {
        if(max->data<temp->data)
        {
            max=temp;
        }
        if(min->data>temp->data)
        {
            min=temp;
        }
        temp=temp->next;
    }

    printf("Maximum: %d\n",max->data);
    printf("Name: %s",max->name);
    printf("Minimum: %d",min->data);
    printf("Name: %s",min->name);

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
        printf("1 for Yes, 0 for No ");
        scanf("%d",&choice);
    }
    display();
    total_sales();
    max_min();
    return 0;
}