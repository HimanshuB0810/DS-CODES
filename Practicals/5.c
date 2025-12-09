// Program based on hashing

#include<stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 10

struct node{
    int data;
    struct node*next;
};

struct node*hashTable[TABLE_SIZE];

struct node*getNode(int data)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

int hashFunction(int key)
{
    return key%TABLE_SIZE;
}

void insert(int key)
{
    int index=hashFunction(key);
    struct node*newnode=getNode(key);
    newnode->next=hashTable[index];
    hashTable[index]=newnode;
    printf("Inserted %d at index %d\n",key,index);
}

void search(int key)
{
    int index=hashFunction(key);
    struct node*temp= hashTable[index];

    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            printf("Key %d found at index %d\n",key,index);
            return;
        }
        temp=temp->next;
    }
}

void deleteKey(int key)
{
    int index=hashFunction(key);
    struct node*temp=hashTable[index];
    struct node*prev=NULL;

    while(temp!=NULL && temp->data!=key)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Key %d not found, cannot delete\n",key);
        return;
    }

    if(prev==NULL)
    {
        hashTable[index]=temp->next;
    }
    else
    {
        prev->next=temp->next;
    }
    free(temp);
    printf("Key %d deleted from index %d\n", key, index);
}

void display()
{
    int i;
    for(i=0;i<TABLE_SIZE;i++)
    {
        struct node*temp=hashTable[i];
        printf("Index %d: ",i);
        if(temp==NULL)
        {
            printf("NULL");
        }
        else
        {
            while(temp!=NULL)
            {
                printf("%d -> ",temp->data);
                temp=temp->next;
            }
            printf("NULL");
        }
        printf("\n");
    }
}

int main()
{
    int choice,key;
    for(int i=0;i<TABLE_SIZE;i++)
    {
        hashTable[i]=NULL;
    }
    while (1) 
    {
        printf("\n--- Hash Table (Separate Chaining) ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            insert(key);
            break;
        case 2:
            printf("Enter key to search: ");
            scanf("%d", &key);
            search(key);
            break;
        case 3:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            deleteKey(key);
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}