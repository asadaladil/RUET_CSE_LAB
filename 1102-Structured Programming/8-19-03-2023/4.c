#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    int a=0;
    for(int i=0;i<n-1;i++)
    {
        if(A[i]>A[i+1])
        {
            a+=(A[i]-A[i+1]);
            A[i+1]=A[i];
        }
    }
    printf("%d",a);
}
