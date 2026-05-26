/*
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||                                                         ||
||     Rajshahi Unversity of Engineering & Technology      ||
||                                                         ||
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||                                                         ||
||                   MD. ASAD-AL-ADIL                      ||
||                                                         ||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| 
*/
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
#define _easy_ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define str string
#define ev(x) x%2==0
#define od(x) x%2==1
#define mod0(x,y) x%y==0 
#define P_B push_back
#define p_b pop_back
#define P_F push_front
#define p_f pop_front
#define pi 3.141592654
int f(int x){if(x==1){return 1;}return x*f(x-1);}
#define __lcm(x,y) (x*y)/__gcd(x,y)
#define A_sort(x) sort(x.begin(),x.end())
#define D_sort(x) sort(x.rbegin(),x.rend())
#define reverse(x) reverse(x.begin(),x.end())
#define yes_or_no cout<<"YES\n":cout<<"NO\n"
#define yess cout<<"YES\n"
#define noo cout<<"NO\n"
#define endl "\n"
#define newl cout<<endl
int main()
{
    int a,b;
    cin>>a>>b;
    int A[a+1][b+1];
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            cin>>A[i][j];
        }
    }
    newl;newl;
    int c,d;
    cin>>c>>d;
    int B[c+1][d+1],R[a+1][d+1];
    if(b==c)
    {
       for(int i=1;i<=c;i++)
       {
            for(int j=1;j<=d;j++)
            {
                cin>>B[i][j];
                R[i][j]=0;
            }
       }
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=d;j++)
            {
                for(int m=1;m<=b;m++) 
                {
                    R[i][j]=R[i][j]+A[i][m]*B[m][j];
                }
            }
       }
       newl;
       for(int i=1;i<=a;i++)
       {
            for(int j=1;j<=d;j++)
            {
                cout<<R[i][j]<<" ";
            }
            newl;
       }
    }
    else
    {
        printf("Matrix Multiplication error");
    }
}