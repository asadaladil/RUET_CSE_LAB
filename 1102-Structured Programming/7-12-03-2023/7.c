// power of anything
#include<stdio.h>
int Abs(int a)
{
    return a>0?a:a*-1;
}
long long int Pow(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    int c=1;
    for(int i=1;i<=Abs(b);i++)
    {
        c*=a;
    }
    return c;
}
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    y>0?printf("%lld",Pow(x,y)):printf("%f",(float)1/Pow(x,y));

}
