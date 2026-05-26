// Next Divisor of 3
#include<stdio.h>
int main()
{
    int t;
    printf("Enter a Number: ");
    scanf("%d",&t);
    printf("%d\n",t-t%3+3);
}
