#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};

struct node*head = NULL, *temp, *newnode, *tail;

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
    if(head == NULL)
    {
        printf("List is Empty!\n");
    }
    else
    {
        temp = head;
        printf("Circular Linked List: ");
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != head);
        printf("\n");
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
        
        newnode = getnode();
        if(newnode == NULL)  // Check if memory allocation failed
        {
            continue;
        }
        
        if(head == NULL)
        {
            head = tail = newnode;
            tail->next = head;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
            tail->next = head;
        }
    }
    
    display();
    return 0;
}