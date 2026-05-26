// Palindrome check
#include<stdio.h>
#include<string.h>
int main()
{
    char r[1000];
    gets(r);
    int a=strlen(r)-1,b;
    b=a%2!=0?(a+1)/2:a/2;
    for(int i=0;i<=b;i++)
    {
        if(r[i]==r[a-i])
        {
            continue;
        }
        else
        {
            printf("%s is NOT PALINDROME\n",r);
            return 0;
        }
    }
    printf("%s is PALINDROME\n",r);
}

