#include<stdio.h>
#include<stdlib.h>
struct employee
{
    char name[30];
    int id;
};
void main()
{
    struct employee *ptr;
    int n=3;
    ptr=(struct employee*)malloc(sizeof(struct employee));
    for(int i=0;i<n;i++)
    {
        printf("Enter Data: \n");
        printf("Enter name: ");
        scanf("%s",&(ptr+i)->name);
        printf("Enter ID: ");
        scanf("%d",&(ptr+i)->id);
    }
    for(int i=0; i<n; i++)
    {
        printf("Name: %s\n",(ptr+i)->name);
        printf("ID: %d\n",(ptr+i)->id);
    }
    free(ptr);
}
