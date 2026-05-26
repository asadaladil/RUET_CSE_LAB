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

class Solution 
{
    public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>>A;
        int n=nums.size();
        int x=1<<n;
        for(int i=0;i<x;i++)
        {
            vector<int>help;
            int m=i,x=0;
            while(m!=0)
            {
                if(od(m))
                {
                    help.push_back(nums[x]);
                }
                x++;
                m=m>>1;
            }
            A.push_back(help);
        }
        return A;
    }
};
int main()
{
    Solution S;
    vector<int>A;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        A.push_back(a);
    }
    vector<vector<int>>sets=S.subsets(A);
    for(int i=0;i<sets.size();i++)
    {
        for(int it:sets[i])
        {
            cout<<it<<" ";
        }
        newl;
    }
}
// algorithm must be noted.......