// nCr
#include<stdio.h>
long long int fact(int a)
{
    int b=1;
    for(int i=2;i<=a;i++)
    {
        b*=i;
    }
    return b;
}
int main()
{
    int n,r;
    scanf("%d%d",&n,&r);
    printf("nCr=%d",fact(n)/(fact(r)*fact(n-r)));
}
