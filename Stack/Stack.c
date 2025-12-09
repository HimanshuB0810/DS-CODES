#include<stdio.h>
# define N 5
int stack[N];
int top=-1;

void push(int x)
{
    if(top>N-1)
    {
        printf("Overflow!");
    }
    else
    {
        top++;
        stack[top]=x;
    }
}

void pop()
{
    if(top==-1)
    {
        printf("Underflow!");
    }
    else
    {
        printf("Element poped is: %d\n",stack[top]);
        top--;
    }
}

void display()
{
    for(int i=top;i>=0;i--)
    {
        printf("%d\t",stack[i]);
    }
}

void main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    display();
    pop();
    display();

}