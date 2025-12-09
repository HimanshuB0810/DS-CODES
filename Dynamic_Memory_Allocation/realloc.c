#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,*ptr;
    printf("Enter the total number of values: ");
    scanf("%d",&n);

    ptr=(int*)calloc(n,sizeof(int));

    printf("Enter the values: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",(ptr+i));
    }

    printf("Enter updated size of n: ");
    scanf("%d",&n);

    int *ptr1;
    ptr1=(int*)realloc(ptr,n*sizeof(int));

    printf("Previous address: %d \t New address: %d\n",ptr,ptr1);


    printf("Entered Values are: ");
    for(i=0;i<n;i++)
    {
        printf("%d\t",*(ptr1+i));
    }
    
    free(ptr1);
    return 0;

    
}