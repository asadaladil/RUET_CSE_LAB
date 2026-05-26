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
const int N=105;
const int M=1e5+5;
ll dp[N][M],wt[N],value[M];
ll Knapsack(int n,int cap)
{
    if(n==0)
    {
        return 0;
    }
    if(dp[n][cap]!=-1)
    {
        return dp[n][cap];
    }
    if(cap<wt[n])
    {
        ll ans=Knapsack(n-1,cap);
        dp[n][cap]=ans;
        return ans;
    }
    ll ans1=value[n]+Knapsack(n-1,cap-wt[n]);
    ll ans2=Knapsack(n-1,cap);
    ll ans=max(ans1,ans2);
    dp[n][cap]=ans;
    return ans;
}
int main()
{
    int n,cap;
    cin>>n>>cap;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        cin>>wt[i]>>value[i];
    }
    cout<<Knapsack(n,cap)<<endl;
}
