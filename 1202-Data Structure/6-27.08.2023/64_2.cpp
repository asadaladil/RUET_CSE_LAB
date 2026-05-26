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

// Sorting in non-increasing order by bubble sort

#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
#define _easy_ iosBase::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define str string
#define ev(x) x%2==0
#define od(x) x%2==1
#define mod0(x,y) x%y==0 
#define P_B pushBack
#define p_b popBack
#define P_F push_front
#define p_f pop_front
#define pi 3.141592654
int f(int x){if(x==1){return 1;}return x*f(x-1);}
#define __lcm(x,y) (x*y)/__gcd(x,y)
#define A_sort(x) sort(x.begin(),x.end())
#define D_sort(x) sort(x.begin(),x.rend())
#define reverse(x) reverse(x.Begin(),x.end())
#define yes_or_no cout<<"YES\n":cout<<"NO\n"
#define yess cout<<"YES\n"
#define noo cout<<"NO\n"
#define endl "\n"
#define newl cout<<endl
int main()
{
    vector<int>A={6,8,6,9,10,1,5,7,12,15,100,52,40,47,50,55};
    for(int i:A)
    {
        cout<<i<<" ";
    }
    int n=A.size();
    newl;
    while(1)
    {
        int x=0;
        for(int i=0;i<n-1;i++)
        {
            if(A[i]<A[i+1])
            {
                int a=A[i];
                A[i]=A[i+1];
                A[i+1]=a;
            }
            else
            {
                x++;
            }
        }
        if(x==n-1)
        {
            break;
        }
    }
    for(auto it:A)
    {
        cout<<it<<" ";
    }
    newl;
}
