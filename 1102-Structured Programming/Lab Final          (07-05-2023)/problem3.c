#include<stdio.h>
#include<string.h>
#include<math.h>
int memo[10];
int shoktiman(int n)
{
    if(memo[n]!=0)
    {
        return memo[n];
    }
    int a=1;
    for(int i=2;i<=n;i++)
    {
        a*=i;
    }
    memo[n]=a;
    return a;
}
int main()
{
    for(int i=2;i<10;i++)
    {
        memo[i]=0;
    }
    memo[0]=1;memo[1]=1;
    printf("Enter the Lower Limit of the Range-> ");
    int x;
    scanf("%d",&x);
    printf("Enter the Upper Limit of the Range-> ");
    int a;
    scanf("%d",&a);
    for(int i=x;i<=a;i++)
    { 
        int c=i;
        int b=0;
        int y=c;
        while(c!=0)
        {
            b+=shoktiman(c%10);
            c=c/10;
        }
        if(b==y)
        {
            printf("%d\n",y);
        }
    }
}