// Element find
#include<stdio.h>
int main()
{
    printf("Enter the number of elements: ");
    int n;
    scanf("%d",&n);
    int A[n];
    printf("Enter %d elements\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    int b;scanf("%d",&b);
    for(int i=0;i<n;i++)
    {
        if(A[i]==b)
        {
            printf("### %d is found at index %d",b,i+1);
            return 0;
        }
    }
    printf("%d is not found",b);
    return 0;
}

