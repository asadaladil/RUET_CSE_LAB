// power in function
#include<stdio.h>
long long int power(int a,int b)
{
    int c=1;
    for(int i=1;i<=b;i++)
    {
        c*=a;
    }
    return c;
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%lld",power(a,b));
}
