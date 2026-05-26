// Maximum Float
#include<stdio.h>
int main()
{
    int n=4;
    float b;
    scanf("%f",&b);
    for(int i=2;i<=4;i++)
    {
        float a;
        scanf("%f",&a);
        if(b<a)
        {
            b=a;
        }
    }
    printf("Maximum id %.2f",b);
}
