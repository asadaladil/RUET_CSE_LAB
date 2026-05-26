// Identity Matrix
#include <stdio.h>
int main()
{
    int r,c,a=0,b=0;
    scanf("%d%d",&r,&c);
    int R[r][c],i,j,m=0;

    if(r==c&&r>1&&c>1)
    {
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                scanf("%d",&R[i][j]);
                if(R[i][j]!=0)
                {
                    m++;
                }
            }
        }
        printf("\n");
        for(i=0;i<r;i++)
        {
            if(R[i][i]==1)
            {
                a++;
            }
        }
        if(a==r&&m==r)
        {
            printf("It is an Identity Matrix\n");
        }
        else
        {
            printf("It is not an Identity Matrix\n");
        }
    }
    else
    {
        printf("It is not a square matrix\n");
    }
    return 0;
}

