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
/*
█████╗ ██████╗ ██╗██╗
██╔══██╗██╔══██╗██║██║
███████║██║  ██║██║██║
██╔══██║██║  ██║██║██║
██║  ██║██████╔╝██║███████╗
╚═╝  ╚═╝╚═════╝ ╚═╝╚════*/
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
#define yes_or_no cout<<"YES\n":cout<<"NO\n";
#define yess cout<<"YES\n"
#define noo cout<<"NO\n"
#define endl "\n"
#define newl cout<<endl

unordered_map<char,int>mp;
void Map(str s)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            mp[s[i]-32]++;
        }
        else
        {
            mp[s[i]]++;
        }
    }
}
bool crazyness(str s)
{
    int l=s.size();
    for(int i=1;i<=ceil(l/2);i++)
    {
        if(s[i-1]!=(s[l-i+1]-32))
        {
            return false;
        }
        else if(s[i-1]!=(s[l-i+1]+32))
        {
            return false;
        }
        else if(s[i-1]==s[l-i-1]&&s[i-1]>='a'&&s[i-1]<='z')
        {
            s[i-1]-=32;
        }
    }
    return true;
}
bool crazy_palindrome()
{
    int odd=0;
    for(auto i:mp)
    {
        if(od(i.second))
        {
            odd++;
        }
    }
    if(odd<=1)
    {
        return true;
    }
    return false;
}
int main()
{
    _easy_
    int x,y;
    cin>>x>>y;
    str r,s;
    cin>>r>>s;
    str total=s+r;
    Map(total);
    int count=0;
    while(total.size()>=y)
    {
        if(crazy_palindrome()&&crazyness(total))
        {
            count++;
        }
        if(total.back()>='a'&&total.back()<='z')
        {
            total[total.size()-1]-=32;
        }
        mp[total[total.size()-1]]--;
        total.pop_back();
    }
    cout<<count;
}