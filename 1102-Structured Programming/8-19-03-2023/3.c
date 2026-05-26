#include <stdio.h>
int main()
{
    int r[5][5],i,j,x,y;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            scanf("%d",&r[i][j]);
            if(r[i][j]==1)
            {
                x=i+1;
                y=j+1;
            }
        }
    }
    int a=x-3,b=y-3;
    if(a<0)
    {
        a=a*(-1);
    }
    if(b<0)
    {
        b=b*(-1);
    }
    printf("%d",a+b);
    return 0;
}
