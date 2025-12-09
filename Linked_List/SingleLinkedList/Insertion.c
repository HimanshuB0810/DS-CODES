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
        printf("The Linked list is empty\n");
    }
    else
    {
        printf("Linked List: ");
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

void Insert_at_Start()
{
    newnode=getnode();
    if(newnode != NULL)
    {
        newnode->next=head;
        head=newnode;
    }
}

void insert_at_end()
{
    newnode=getnode();
    if(newnode != NULL)
    {
        if(head == NULL)  // Handle empty list case
        {
            head = newnode;
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
}

void Insert_at_Position()
{
    int pos, i = 1;
    int count = 0;
    
    // Count nodes
    temp = head;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    
    printf("Current list has %d nodes\n", count);
    printf("Enter Position (1 to %d): ", count + 1);
    scanf("%d", &pos);
    
    if(pos < 1 || pos > count + 1)
    {
        printf("Invalid Position! Valid range: 1 to %d\n", count + 1);
    }
    else if(pos == 1)  // Insert at beginning
    {
        Insert_at_Start();
    }
    else if(pos == count + 1)  // Insert at end
    {
        insert_at_end();
    }
    else  // Insert at middle position
    {
        newnode = getnode();
        if(newnode != NULL)
        {
            temp = head;
            while(i < pos - 1)  // Traverse to (pos-1)th node
            {
                temp = temp->next;
                i++;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}

int main()
{
    int choice = 1;
    head = NULL;  // Initialize head
    
    printf("=== Creating Initial Linked List ===\n");
    while(choice)
    {
        printf("Do you want to add another node? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);
        if(choice == 0)
        {
            break;
        }
        if(head == NULL)
        {
            head = getnode();
            temp = head;
        }
        else
        {
            newnode = getnode();
            if(newnode != NULL)
            {
                temp->next = newnode;
                temp = newnode;
            }
        }
    }
    
    printf("\n=== Initial List ===\n");
    display();
    
    printf("\n=== Testing Insert at Start ===\n");
    Insert_at_Start();
    display();
    
    printf("\n=== Testing Insert at End ===\n");
    insert_at_end();
    display();
    
    printf("\n=== Testing Insert at Position ===\n");
    Insert_at_Position();
    display();
    
    return 0;
}