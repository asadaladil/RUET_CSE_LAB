// Minimum value print
#include<stdio.h>
int main()
{
    int n,a;
    scanf("%d",&n);
    int b;
    scanf("%d",&a);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&b);
        if(a>b){a=b;}
    }
    printf("%d\n%d",a,b);
}
