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
ll f(ll x){if(x<=1){return 1;}return x*f(x-1);}
#define __lcm(x,y) (x*y)/__gcd(x,y)
#define A_sort(x) sort(x.begin(),x.end())
#define D_sort(x) sort(x.rbegin(),x.rend())
#define Reverse(x) reverse(x.begin(),x.end())
#define Vary(A,x,y,n) transform(A.begin()+x,A.begin()+y,A.begin()+x,[](int a){return a+n;})
#define Vary_perm(x) next_permutation(x.begin(),x.end())
#define yes_or_no cout<<"YES\n":cout<<"NO\n"
#define yess cout<<"YES\n"
#define noo cout<<"NO\n"
#define endl "\n"
#define newl cout<<endl
const int N=100;
const int M=100;
ll A[N+1][M+1];
int n,m;
ll dp[N+1][M+1];
bool is_inside(int x,int y)
{
    if(x<=n&&x>0&&y<=m&&y>0)
    {
        return true;
    }
    return false;
}
ll path_sum(int x,int y)
{
    ll ans1=-1e10;
    if(x==n&&y==m)
    {
        dp[x][y]=A[x][y];
        return A[x][y];
    }
    if(dp[x][y]!=0)
    {
        return dp[x][y];
    }
    if(is_inside(x+1,y))
    {
        ans1=max(ans1,A[x][y]);
        ans1+=path_sum(x+1,y);
    }
    ll ans2=-1e10;
    if(is_inside(x,y+1))
    {
        ans2=max(ans2,A[x][y]);
        ans2+=path_sum(x,y+1);
    }
    dp[x][y]=max(ans1,ans2);
    return max(ans1,ans2);
}
int main()
{
    memset(dp,0,sizeof(dp));
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>A[i][j];
        }
    }
    cout<<path_sum(1,1);newl;
}
