#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char a[1000];
    printf("Enter a number : ");
    scanf("%s",a);
    printf("The Sum of the digit of %s = ",a);
    int sum=0;
    int b=strlen(a);
    for(int i=0;i<b;i++)
    {
        sum+=a[i]-'0';
    }
    printf("%d",sum);
}
