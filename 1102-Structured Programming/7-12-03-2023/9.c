// odd index multiplication
#include<stdio.h>
#include<string.h>
int pre_odd(char r[1000])
{
    int a=strlen(r),b=1;
    for(int i=0;i<a;i+=2)
    {
        if(r[i]=='0')
        {
            return 0;
        }
        b*=r[i]-'0';
    }
    return b;
}
int main()
{
    char r[1000];
    scanf("%s",r);
    printf("%d\n",pre_odd(r));
}
