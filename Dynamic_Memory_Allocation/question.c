#include<stdio.h>
#include<stdlib.h>

struct person
{
    char name[20];
    int age;
};

int main()
{
    struct person *ptr;
    int i;
    ptr=(struct person*)malloc(3*sizeof(struct person));

    for(i=0;i<3;i++)
    {
        printf("Enter Name: ");
        scanf("%s",&(ptr+i)->name);

        printf("Enter Age: ");
        scanf("%d",&(ptr+i)->age);
    }

    for(i=0;i<3;i++)
    {
        printf("Name: %s",(ptr+i)->name);
        printf("Age: %d",(ptr+i)->age);
    }
    free(ptr);
}

