// Fibonacci pattern
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    A[0]=0;A[1]=1;
    printf("The sequence upto %dth term\n",n);
    for(int i=2;i<=n;i++)
    {
        A[i]=A[i-2]+A[i-1];
    }
    for(int i=0;i<n;i++)
    {
        printf("%d->",A[i]);
    }
    printf("%d",A[n]);
}
