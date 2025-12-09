// Program based on circular linked list: Implement a music playlist where once the last song finishes playing, it loops back to the
// first song. This allows for continuous playback without needing to restart from the beginning. Perform following operations on it:
// 1. Inserting a Song (end)
// 2. Deleting a Song (end)
// 3. Playing Songs (Traversal)
// 4. Searching for a Song
// 5. Displaying the Playlist
// 6. Count the Songs

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char name[50];
    struct node* next;
};
struct node* tail,*temp,*newnode;
struct node*getnode()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter Name of the Song : ");
    scanf("%s",&newnode->name);
    newnode->next=NULL;
    return newnode;
}

void insert_at_end()
{
    if (tail == NULL)    
    {
        newnode=getnode();
        tail = newnode;
        tail->next = tail;   
    }
    else
    {
        newnode=getnode();
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
    
}

void delete_at_end()
{
    struct node* prevsong;
    temp=tail->next;
    while(temp->next!=tail->next)
    {
        prevsong=temp;
        temp=temp->next;
    }
    prevsong->next=tail->next;
    tail=prevsong;
    free(temp);
   
}

void playsong()
{
    temp=tail->next;
    while (temp->next!=tail->next)
    {
        printf("Now Playing: \n");
        printf("%s\n",temp->name);
        temp=temp->next;
    }
    printf("Now Playing: \n");
    printf("%s\t",temp->name);
}

void search_a_song()
{
    char songname[50];
    int pos=1;
    printf("Enter song to search: ");
    scanf("%s",&songname);
    temp=tail->next;
    while(temp->next!=tail->next)
    {
        if(strcmp(songname,temp->name)==0)
        {
            printf("%s song found at position: %d",songname,pos);
            return;
        }
        temp=temp->next;
        pos++;
    }
    
        if(strcmp(songname,temp->name)==0)
        {
            printf("%s song found at position: %d",songname,pos);
        }
        else
        {
            printf("Song not found");
        }
}

void count_songs()
{
    temp=tail->next;
    int count=0;
    while(temp->next!=tail->next)
    {
        count++;
        temp=temp->next;
    }
    printf("Total Number of Songs are: %d",count+1);

}
void display()
{
    temp=tail->next;
    while (temp->next!=tail->next)
    {
        printf("%s ->",temp->name);
        temp=temp->next;
    }
    printf("%s",temp->name);
    printf("\n");
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n\n--- Music Playlist Menu ---\n");
        printf("1. Insert Song\n");
        printf("2. Delete Song\n");
        printf("3. Play Songs\n");
        printf("4. Search Song\n");
        printf("5. Display Playlist\n");
        printf("6. Count Songs\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            insert_at_end();
            break;

            case 2:
            delete_at_end();
            break;

            case 3:
            playsong();
            break;

            case 4:
            search_a_song();
            break;

            case 5:
            display();
            break;

            case 6:
            count_songs();
            break;

            case 7:
            printf("Exiting!..");
            exit(0);

            default:
            printf("Invalid number!");
        }
    }
    return 0;
    
    
}

// int choice=1;
    // while (choice)
    // {
    //     if(tail==NULL)
    // {
    //     newnode=getnode();
    //     tail=newnode;
    //     tail->next=tail;
    // }
    // else
    // {
    //     newnode=getnode();
    //     newnode->next=tail->next;
    //     tail->next=newnode;
    //     tail=newnode;
    // }
    // printf("1 for yes, 0 for no: ");
    // scanf("%d",&choice);
    // }

    