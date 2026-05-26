// Range Summation of divisor 3
#include<stdio.h>
int main()
{
    int x1,x2;
    scanf("%d%d",&x1,&x2);
    int sum=0;
    if(x1%3!=0)
    {
        x1=x1-x1%3+3;
    }
    for(int i=x1;i<=x2;i+=3)
    {
        sum+=i;
    }
    printf("%d\n",sum);
}
