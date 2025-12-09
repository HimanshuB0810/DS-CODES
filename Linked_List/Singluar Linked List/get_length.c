#include<stdlib.h>
#include<stdio.h>

struct node
{
    int data;
    struct node*next;
};
void get_length()
{
    int count=0;
    struct node*temp;
    struct node*head;
    temp=head;
    while(temp!=0)
    {
        count++;
        temp=temp->next;
    }
    printf("Length:",count);

}