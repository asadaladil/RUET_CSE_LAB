// Number of even elements
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int A[n],a=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        if(A[i]%2!=0)
            a++;
    }
    printf("%d",a);
    return 0;
}
/*
// print even and odd of array
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int A[n],O[n],E[n],a=0,b=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        if(A[i]%2!=0)
        {
            O[a]=A[i];
            a++;
        }
        else
        {
            E[b]=A[i];
            b++;
        }
    }
    for(int i=0;i<a;i++)
    {
        printf("%d ",O[i]);
    }
    printf("\n");
    for(int i=0;i<b;i++)
    {
        printf("%d ",E[i]);
    }
    return 0;
}
*/
