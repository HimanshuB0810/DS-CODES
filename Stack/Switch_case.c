# include<stdio.h>
#include<stdlib.h>
# define N 5
int stack[N];
int top=-1;
int main()
{
    while(1)
    {
        int choice;
        printf("Enter 1 for push\n");
        printf("Enter 2 for pop\n");
        printf("Enter 3 for peek\n");
        printf("Enter 4 for display\n");
        printf("Enter 5 for exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            push();
            break;

            case 2:
            pop();
            break;

            case 3:
            peek();
            break;

            case 4:
            display();
            break;

            case 5:
            exit(0);
            break;

            default:
            printf("Enter valid choice");
        }
    }
}

void push()
{
    int data;
    printf("Enter data you want to push: ");
    scanf("%d",&data);

    if(top==N-1)
    {
        printf("Overflow\n");
    }
    else
    {
        top++;
        stack[top]=data;
    }
}

void pop()
{
    if(top==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        int x;
        x=stack[top];
        printf("Element deleted is: %d\n",x);
        top--;
    }
}

void peek()
{
    if(top==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        int x;
        x=stack[top];
        printf("Element at the top is: %d\n",x);
    }
}

void display()
{
    int i;
    for(i=top;i>=0;i--)
    {
        printf("%d\t",stack[i]);
    }
    printf("\n");
}


