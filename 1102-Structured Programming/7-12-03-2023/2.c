// difference in function
#include<stdio.h>
int difference(int a,int b)
{
    int c=a>b?a-b:b-a;
    return c;
}
int main()
{
    printf("Enter 2 numbers: ");
    int a,b;
    scanf("%d%d",&a,&b);
    printf("Difference is %d",difference(a,b));
}
