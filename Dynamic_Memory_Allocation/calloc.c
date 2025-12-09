#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,*ptr;
    printf("Enter the total number of values: ");
    scanf("%d",&n);

    ptr=(int*)calloc(n,sizeof(int));

    printf("Enter the values: ");
    for(i=0;i<3;i++)
    {
        scanf("%d",(ptr+i));
    }

    printf("Entered values are: \n");
     for(i=0;i<3;i++)
    {
        printf("%d\t",*(ptr+i));
    }

    free(ptr);
    return 0;
}