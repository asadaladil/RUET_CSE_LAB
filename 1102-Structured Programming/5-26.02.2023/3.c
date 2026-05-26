//max of array element
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int A[n],a;
    scanf("%d",&a);
    A[0]=a;
    for(int i=1;i<n;i++)
    {
        scanf("%d",&A[i]);
        if(a<A[i])
            a=A[i];
    }
    printf("%d",a);
    return 0;
}

