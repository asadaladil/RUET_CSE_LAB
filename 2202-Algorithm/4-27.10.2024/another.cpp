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
using vec_1D=vector<ll>;
using vec_2D=vector<vector<ll>>;
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

vec_1D Merge(vec_1D left,vec_1D right)
{
    int n=left.size()+right.size(),l=0,r=0;
    vec_1D ans(n);
    for(int i=0;i<n;i++)
    {
        if(l!=int(left.size())&& left[l]<=right[r] || r==int(right.size()))
        {
            ans[i]=left[l];
            l++;
        }
        else if(r!=int(right.size())&&right[r]<=left[l] || l==int(left.size()))
        {
            ans[i]=right[r];
            r++;
        }
    }
    return ans;
}

vec_1D Merge_Sort(int l, int h, vec_1D arr)
{
    if(l==h)
    {
        return {arr[l]};
    }
    int mid=(l+h)/2;
    vec_1D left=Merge_Sort(l,mid,arr);
    vec_1D right=Merge_Sort(mid+1,h,arr);
    return Merge(left,right);

}
int main()
{
    vec_1D list={10,4,8,25,6,1,9,5,7,0,0,0};
    vec_1D sorted_list=Merge_Sort(0,list.size()-1,list);
    for(auto i:sorted_list)
    {
        cout<<i<<" ";
    }
}
