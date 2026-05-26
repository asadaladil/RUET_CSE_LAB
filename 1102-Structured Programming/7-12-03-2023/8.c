// digit_frequency
#include<stdio.h>
#include<string.h>
int digit_frequency(char r[1000],char s)
{
    int a=strlen(r),b=0;
    for(int i=0;i<a;i++)
    {
        if(r[i]==s)
        {
            b++;
        }
    }
    return b;
}
int main()
{
    char r[1000],s;
    scanf("%s %c",r,&s);
    printf("%d\n",digit_frequency(r,s));
}
