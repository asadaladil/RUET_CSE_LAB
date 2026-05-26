// Summation o first and first digit
#include<stdio.h>
int main()
{
    long long int a;
    scanf("%lld",&a);
    int sum=a%10+a/1000000;
    printf("The summation of first & last digit %d",sum);
}
