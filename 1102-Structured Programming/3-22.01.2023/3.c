// Power of 2
#include<stdio.h>
int main()
{
    int n;
    printf("N=");
    scanf("%d",&n);
    for(int i=1;i<=n;i*=2)
    {
        printf("%d->",i);
    }
    printf(".");
}
