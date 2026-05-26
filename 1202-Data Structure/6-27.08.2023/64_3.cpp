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

// https://cses.fi/problemset/task/1755

#include<bits/stdc++.h>
using namespace std;
#define _easy_ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
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
#define vary(A,x,y,n) transform(A.begin()+x,A.begin()+y,A.begin()+x,[](int a){return a+n;})
#define vary_perm(x) next_permutation(x.begin(),x.end())
#define yes_or_no cout<<"YES\n":cout<<"NO\n"
#define yess cout<<"YES\n"
#define noo cout<<"NO\n"
#define endl "\n"
#define newl cout<<endl
int main()
{
    string s,r="";
    cin>>s;
    char d;
    int a;
    int n=s.size();
    unordered_map<char,int>str;
    for(int i=0; i<n; i++)
    {
        str[s[i]]++;
    }
    int odd=0;
    for(auto p:str)
    {
        if(p.second%2==1)
        {
            odd++;
            d=p.first;
            a=p.second;
            if(odd>1)
            {
                cout<<"NO SOLUTION\n";
                return 0;
            }
        }
    }
    for(auto p:str)
    {
        if(p.second%2==0)
        {
            for(int i=1; i<=p.second/2; i++)
            {
                r+=p.first;
            }
        }
    }
    cout<<r;
    if(odd==1)
    {
        for(int i=1;i<=a;i++)
        {
            cout<<d;
        }
    }
    string k="";
    for(int i=r.size()-1;i>=0;i--)
    {
        k+=r[i];
    }
    cout<<k;
}
