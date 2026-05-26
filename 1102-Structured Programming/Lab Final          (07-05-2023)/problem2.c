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
    printf("Enter a number : ");
    int x;
    scanf("%d",&x);
    int b=0;
    int y=x;
    if(y==0)
    {
        printf("%d is not a ShoktiMaN number.",y);
    }
    while(x!=0)
    {
        b+=shoktiman(x%10);
        x=x/10;
    }
    b==y?printf("%d is a ShoktiMaN number.",y):printf("%d is not a ShoktiMaN number.",y);
}