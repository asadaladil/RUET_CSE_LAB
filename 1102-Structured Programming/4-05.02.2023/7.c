// Divisor summation = value
#include<stdio.h>
int perfect(int n)
{
    int sum=0;
    for(int i=1;i<=n/2;i++)
    {
        if(n%i==0)
        {
            sum+=i;
        }
    }
    if(sum==n)
    {
        return 1;
    }
    return 0;
}
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    for(int i=x;i<=y;i++)
    {
        if(perfect(i)==1)
        {
            printf("%d ",i);
        }
    }
}
