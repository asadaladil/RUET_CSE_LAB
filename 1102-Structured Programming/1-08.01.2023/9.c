// Hour minute second calculation
#include<stdio.h>
int main()
{
    long long int a;
    scanf("%lld",&a);
    printf("%lld hour %lld minutes %lld seconds",a/3600,(a%3600)/60,a%60);
}
