// Summation of the square of all the integers
#include<stdio.h>
int main()
{
    int n,sum=0;
    printf("N=");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        sum+=i*i;
    }
    printf("\nSummation of the square of all the integers from 1 to %d = %d\n",n,sum);
}

