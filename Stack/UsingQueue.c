#include<stdio.h>
# define N 5
int q1[N],q2[N];
int front1=-1, rear1=-1;
int front2=-1, rear2=-1;
int count=0;

void enqueue1(int data)
{
    if(rear1==N-1)
    {
        printf("Overflow");
    }
    else
    {
        if(front1==-1)
        {
            front1=0;
        }
        rear1++;
        q1[rear1]=data;
    }
}

int dequeue1()
{   
    int data=q1[front1];
    if(front1==rear1)
    {
        front1=rear1=-1;
    }
    else
    {
        front1++;
    }
    return data;
}

void enqueue2(int data)
{
    if(rear2==N-1)
    {
        printf("Overflow");
    }
    else
    {
        if(front2==-1)
        {
            front2=0;
        }
        rear2++;
        q2[rear2]=data;
    }
}

int dequeue2()
{   
    int data=q2[front2];
    if(front2==rear2)
    {
        front2=rear2=-1;
    }
    else
    {
        front2++;
    }
    return data;
}

void push(int x)
{
    enqueue1(x);
    count++;
}

void pop()
{
    int i,a,b;
    if(front1 ==-1)
    {
        printf("Underflow");
    }
    else
    {
        // move all the elements except the last from q1 to q2
        for(i=0;i<count-1;i++)
        {
            a=dequeue1();
            enqueue2(a);
        }
        // remove the last element
        b=dequeue1();
        printf("Pooped Element is: %d",b);
        printf("\n");
        count--;
    }
    
    // move all elements back from q2 to q1
    for(i=0;i<count;i++)
    {
        a=dequeue2();
        enqueue1(a);
    }
}

void display()
{
    int i;
    for(i=front1;i<=rear1;i++)
    {
        printf("%d\t",q1[i]);
    }
    printf("\n");
}

void main()
{
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
}
