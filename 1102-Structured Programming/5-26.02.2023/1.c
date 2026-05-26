// Array element
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("The elements in reverse order:\n");
    for(int i=n-1;i>=0;i--)
    {
        printf("Element[%d]=%d\n",i+1,A[i]);
    }
    return 0;
}
