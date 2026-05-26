// Summation of a series
#include<stdio.h>
int main()
{
    int n,sum=0;
    printf("N=");
    scanf("%d",&n);
    for(int i=n;i>1;i--)
    {
        sum+=(i+1)*i;
        printf("%d*%d + ",i+1,i);
    }
    printf("2*1 = %d",sum+2);
}
