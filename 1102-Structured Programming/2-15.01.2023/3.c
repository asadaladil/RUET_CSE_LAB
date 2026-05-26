// Arithmetic Operation
#include<stdio.h>
int main()
{
    int a,b;
    printf("Enter two number:\n");
    scanf("%d%d",&a,&b);
    printf("\nOperation to be performed(+,-,*,/): ");
    char c;
    scanf("\n%c",&c);
    switch(c)
    {
    case '+':
        printf("The result = %d\n",a+b);break;

    case '-':
        printf("The result = %d\n",a>b?a-b:b-a);break;
    case '*':
        printf("The result = %d\n",a*b);break;
    case '/':
        printf("The result = %.2f\n",a>b?(double)a/b:(double)b/a);break;
    default:
        printf("Invalid\n");
    }
}
