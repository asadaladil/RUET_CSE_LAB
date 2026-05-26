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
vector<int>divisor(int n)
{
    vector<int>A;
    for(int i=2;i<=n;i++)
    {
        if(od(i)&&mod0(n,i))
        {
            A.push_back(i);
        }
    }
    return A;
}
bool is_prime(int i)
{
    if(ev(i)&i>2)
    {
        return false;
    }
    for(int x=2;x<=i;x++)
    {
        if(mod0(i,x))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int m,n;
    cin>>m>>n;
    vector<int>A,B;
    A=divisor(m);
    B=divisor(n);
    int x=0,y=0;
    for(int i=0;i<A.size();i++)
    {
        if(is_prime(A[i]))
        {
            x++;
        }
    }
    for(int i=0;i<B.size();i++)
    {
        if(is_prime(B[i]))
        {
            y++;
        }
    }
    x==y?cout<<"YES\n":cout<<"NO\n";
}
