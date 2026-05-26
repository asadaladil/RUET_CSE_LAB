// Fibonacci element find
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int A[10000];
    A[0]=0;
    A[1]=1;
    for(int i=0; i>=0; i++)
    {
        if(i<2)
        {
            if(A[i]==n)
            {
                printf("The term %d is in the sequence\n",n);
                return 0;
            }
            continue;
        }
        A[i]=A[i-2]+A[i-1];
        if(A[i]==n)
        {
            printf("The term %d is in the sequence\n",n);
            return 0;
        }
        if(A[i]>n)
        {
            printf("The term %d is not in the sequence\n",n);
            return 0;
        }
    }

}

