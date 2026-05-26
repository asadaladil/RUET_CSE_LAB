// Class Test Marks
#include<stdio.h>
int main()
{
    int b;
    scanf("%d",&b);
    int c=b,av=b;
    for(int i=2;i<=4;i++)
    {
        int a;
        scanf("%d",&a);
        av+=a;
        if(c>a)
        {
            c=a;
        }
    }
    printf("%d\n",(av-c)%3==0?(av-c)/3:(av-c)/3+1);
}
