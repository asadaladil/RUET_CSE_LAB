#include<stdio.h>
int main()
{
    int n,e=0,p=0,o=0,N=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        if(a>0){p++;}
        else if(a!=0){N++;}
        if(a%2==0){e++;}
        else{o++;}
    }
    printf("Even: %d\n",e);
    printf("Odd:  %d\n",o);
    printf("Positive: %d\n",p);
    printf("Negative: %d",N);
}

