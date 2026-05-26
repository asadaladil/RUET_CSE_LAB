// reverse right angle pattern
#include <stdio.h>
int main()
{
    printf("Enter the number of rows: ");
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=n;j>=i;j--)
        {
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");
}
