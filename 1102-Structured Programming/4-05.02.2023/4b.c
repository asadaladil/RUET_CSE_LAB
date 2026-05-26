// right angle pattern with value
#include <stdio.h>
int main()
{
    printf("Enter the number of rows: ");
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            printf("%d ",i);
        }
        printf("\n");
    }
    printf("\n");
}
