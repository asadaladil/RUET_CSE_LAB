// Factorial
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    long long int f=1;
    for(int i=2;i<=n;i++)
    {
        f*=i;
    }
    printf("%lld\n",f);
}
