// rectangle in function
#include<stdio.h>
void rectangle(int a,int b)
{
    printf("Area is %d\nPerimeter is %d\n",a*b,(a+b)*2);
}
int main()
{
    int a,b;
    printf("Length of rectangle: ");
    scanf("%d",&a);
    printf("Width of rectangle: ");
    scanf("%d",&b);
    rectangle(a,b);
}

