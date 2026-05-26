// Special pattern
#include<stdio.h>
int main()
{
   int n;
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
       int x=2*i-1,m=1;
       for(int j=1;j<=2*n-i*2;j++)
       {
           printf(" ");
       }
       for(int j=1;j<=x;j++)
       {
           if(j<(x/2+1))
           {
               printf("%d ",m);
               m++;
           }
           else if(j==x/2+1)
           {
               printf("%d ",m);
           }
           else
           {
               m--;
               printf("%d ",m);
           }
       }
       printf("\n");
   }

}
