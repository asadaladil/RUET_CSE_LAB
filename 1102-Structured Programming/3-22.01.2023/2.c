// 1 to n value print
#include<stdio.h>
int main()
{
    int n;
    printf("N=");
    scanf("%d",&n);
    for(int i=1;i<=n;i+=3)
    {
        printf("%d->",i);
    }
    printf(".");
}
