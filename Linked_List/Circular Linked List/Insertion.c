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
        printf("\n");
    }


    int get_length()
    {
        int count = 0;
        
        // Check if list is empty
        if(tail == NULL)
        {
            return 0;
        }
        
        // Start from head (tail->next)
        temp = tail->next;
        struct node* start = temp;  // Remember the starting point
        
        // Count the first node
        count = 1;
        temp = temp->next;
        
        // Continue counting until we reach the starting point again
        while(temp != start)
        {
            count++;
            temp = temp->next;
        }
        
        return count;
    }

    void insert_at_start()
    {
        newnode=getnode();
        if(tail==NULL)
        {
            tail=newnode;
            tail->next=newnode;
        }
        else
        {
            newnode->next=tail->next;
            tail->next=newnode;
        }
    }

    void insert_at_end()
    {
        newnode=getnode();
        if(tail==NULL)
        {
            tail=newnode;
            tail->next=newnode;
        }
        else
        {
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
    }

    void insert_at_position()
    {
        int pos,i=1;
        int l=get_length();
        printf("Enter Position: ");
        scanf("%d",&pos);
        if(pos==1)
        {
            insert_at_start();
        }
        if(pos<1 || pos>l)
        {
            printf("Invlaid Position!");
        }
        else
        {
            while(i<pos-1)
            {
                temp=temp->next;
                i++;
            }
            newnode=getnode();
            newnode->next=temp->next;
            temp->next=newnode;
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
        insert_at_start();
        display();
        insert_at_end();
        display();
        insert_at_position();
        display();
        return 0;
    }

