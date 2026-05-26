// nPr
#include<stdio.h>
long long int npr(int a,int b)
{
    long long int c=1;
    for(int i=0;i<b;i++)
    {
        c*=(a-i);
    }
    return c;
}
int main()
{
    int n,r;
    scanf("%d%d",&n,&r);
    printf("nPr=%d",npr(n,r));
}
