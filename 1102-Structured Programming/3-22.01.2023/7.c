// Power value print
#include<stdio.h>
int main()
{
    int n,x;
    printf("X=");
    scanf("%d",&x);
    printf("N=");
    scanf("%d",&n);
    if(n==0)
    {
        printf("1 [%d^%d]",x,n);
        return 0;
    }
    if(n<0)
    {
        float powr=1.0;
        for(int i=1;i<=-n;i++)
        {
            powr=powr*(1/(float)x);
        }
        printf("%f [%d^%d]",powr,x,n);
        return 0;
    }
    int powr=1;
    for(int i=1;i<=n;i++)
    {
        powr=powr*x;
    }
    printf("%d [%d^%d]",powr,x,n);
}
