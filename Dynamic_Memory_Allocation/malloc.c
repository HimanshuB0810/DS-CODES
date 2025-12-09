#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,*ptr;
    printf("Enter total number of values: ");
    scanf("%d",&n);

    ptr=(int*)malloc(n*sizeof(int));

    printf("Enter the values: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",(ptr+i));
    }

    printf("Entered values are :\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",*(ptr+i));
    }
    free(ptr);
    return 0;
}



