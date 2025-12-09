#include<stdlib.h>
#include<stdio.h>

struct node
{
    int data;
    struct node*next;
    struct node*prev;
};

struct node*head=NULL,*tail,*newnode,*temp;
struct node* getnode()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

void display()
{
    temp=head;
    while(temp!=0)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void reverse_DLL()
{
    struct node*current_node,*next_node;
    current_node=head;
    while(current_node!=0)
    {
        next_node=current_node->next;
        current_node->next=current_node->prev;
        current_node->prev=next_node;
        current_node=next_node;
    }

    // to reverse head and tail
    current_node=head;
    head=tail;
    tail=current_node;
}

int main()
{
    int choice=1;
    while(choice)
    {
        printf("Do you want to continue?, 0 for NO , 1 for YES: ");
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
    reverse_DLL();
    display();
    return 0;
}