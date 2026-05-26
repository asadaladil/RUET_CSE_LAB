// Divisor of 3 in reverse
#include<stdio.h>
int main()
{
    int n;
    printf("N=");
    scanf("%d",&n);
    n=n-n%3;
    for(int i=n;i>=1;i-=3)
    {
        printf("%d->",i);
    }
    printf(".");
}
