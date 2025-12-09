    #include<stdio.h> 
    #include<stdlib.h>

    struct Person
    {
        char name[20];
        int age;
    };

    int main()
    {
        struct Person *ptr;
        int i,n;
        printf("Enter number of person: ");
        scanf("%d",&n);

        ptr=(struct Person*)malloc(n*sizeof(struct Person));

        for(i=0;i<n;i++)
        {
            printf("Enter Data: ");
            scanf("%s %d",&(ptr+i)->name,&(ptr+i)->age);
        }
        for(i=0;i<n;i++)
        {
            printf("Name: %s and Age: %d",(ptr+i)->name,(ptr+i)->age);
        }
        return 0;

    }
