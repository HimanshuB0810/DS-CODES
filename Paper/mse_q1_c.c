#include<stdio.h>
#include<stdlib.h>
struct employee{
    char name[30];
    int id;
};
int main()
{
    struct employee *ptr;
    int i,n=3;
    ptr=(struct employee*)malloc(n*sizeof(struct employee));

    for(i=0;i<n;i++)
    {
        printf("Enter Info of %d\n",i+1);
        printf("Enter Name: ");
        scanf("%s",&(ptr+i)->name);
        printf("Enter ID: ");
        scanf("%d",&(ptr+i)->id);
    }

    for(i=0;i<n;i++)
    {
        printf("Name: %s\n",(ptr+i)->name);
        printf("ID: %d\n",(ptr+i)->id);
    }
    free(ptr);
}