// maximum
#include<stdio.h>
int maxx(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int m1=maxx(a,b);
    int m2=maxx(c,d);
    printf("Maximum is %d",maxx(m1,m2));
}
