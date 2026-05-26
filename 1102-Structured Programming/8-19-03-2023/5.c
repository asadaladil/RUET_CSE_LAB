#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
    {
        A[i]=0;
    }
    for(int i=0;i<n-1;i++)
    {
        int a;
        scanf("%d",&a);
        A[a]++;
    }
    for(int i=1;i<n;i++)
    {
        if(A[i]==0)
        {
            printf("%d",i);
            break;
        }
    }

}
