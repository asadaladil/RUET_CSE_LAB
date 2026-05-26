// Average of array elements
#include<stdio.h>
int main()
{
    int  n;
    scanf("%d",&n);
    int A[n],sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        sum+=A[i];
    }
    printf("%.2f",(float)sum/n);
    return 0;
}

