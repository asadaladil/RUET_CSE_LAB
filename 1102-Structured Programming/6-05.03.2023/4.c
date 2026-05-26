// 1 change palindrome
#include<stdio.h>
#include<string.h>
int main()
{
    char r[1000];
    gets(r);
    int a=strlen(r)-1,b,c=0;
    b=a%2!=0?(a+1)/2:a/2;
    for(int i=0;i<b;i++)
    {
        if(r[i]==r[a-i])
        {
            c++;
        }
    }
    if(strlen(r)%2!=0&&b-c==0)
    {
        printf("Yes\n");
        return 0;
    }
    b-c==1?printf("Yes\n"):printf("NO\n");
}

