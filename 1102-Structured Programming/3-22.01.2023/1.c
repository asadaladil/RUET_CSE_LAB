// Dollar print
#include<stdio.h>
int main()
{
    int n;
    printf("N=");
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        printf("$-");
    }
    printf("$.");
}
