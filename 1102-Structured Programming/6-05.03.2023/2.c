// string reverse
#include<stdio.h>
#include<string.h>
int main()
{
    char r[1000],s[1000];
    gets(r);int a=0;
    for(int i=strlen(r)-1;i>=0;i--)
    {
        s[a]=r[i];a++;
    }
    s[a]='\0';
    puts(s);
}
