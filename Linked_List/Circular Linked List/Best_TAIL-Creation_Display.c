#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};

struct node *temp, *newnode, *tail=NULL;

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

// TAIL->NEXT = ADDRESS OF THE FIRST NODE (HEAD) ALWAYS
void display()
{
    if(tail==NULL)
    {
        printf("List is empty!");
    }
    else
    {
        temp=tail->next;
        while(temp->next!=tail->next)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}

int main()
{
    int choice = 1;
    
    while(choice)
    {
        printf("Do you want to add newnode? 0 for NO, 1 for YES: ");
        scanf("%d", &choice);
        
        if(choice == 0)
        {
            break;
        }
        if(tail == NULL)
        {
            newnode=getnode();
            tail=newnode;
            tail->next=tail;
        }
        else
        {
            newnode=getnode();
            newnode->next=tail->next; //Imp to do first cus then we dont have the address of the first node (head)
            tail->next=newnode;
            tail=newnode;
        }
    }
    
    display();
    return 0;
}