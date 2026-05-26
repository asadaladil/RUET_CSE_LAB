// Transpose Matrix
#include <stdio.h>
int main()
{
    int r,c,i,j,a;
    scanf("%d%d",&r,&c);
    int R[r][c],A[c][r];
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            scanf("%d",&R[i][j]);
        }
    }
    printf("Transpose of that Matrix:\n");
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
            A[i][j]=R[j][i];
        }
    }
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
