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
using vec_1D=vector<double>;
using vec_2D=vector<vector<double>>;
using Pvec_1D=vector<pair<double,int>>;
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

Pvec_1D Ratio;
double R[1000];
Pvec_1D Merge(Pvec_1D left,Pvec_1D right)
{
    int n=left.size()+right.size(),l=0,r=0;
    Pvec_1D ans(n);
    for(int i=0;i<n;i++)
    {
        if(l!=int(left.size())&&left[l].first<=right[r].first||r==int(right.size()))
        {
            ans[i].first=left[l].first;
            ans[i].second=left[l].second;
            l++;
        }
        else if(r!=int(right.size())&&right[r].first<=left[l].first||l==int(left.size()))
        {
            ans[i].first=right[r].first;
            ans[i].second=right[r].second;
            r++;
        }
    }
    return ans;
}
Pvec_1D Merge_Sort(int l, int h, Pvec_1D arr)
{
    if(l==h)
    {
        return {make_pair(arr[l].first,arr[l].second)};
    }
    int mid=(l+h)/2;
    Pvec_1D left=Merge_Sort(l,mid,arr);
    Pvec_1D right=Merge_Sort(mid+1,h,arr);
    return Merge(left,right);

}
double Frac_Knapsack(double capacity,vec_1D weight,vec_1D benefit)
{
    double total_benefit=0.0;
    for(auto i:Ratio)
    {
        if (capacity>=weight[i.second])
        {
            total_benefit+=benefit[i.second];
            capacity-=weight[i.second];
            R[i.second]=1;
        }
        else if (capacity<weight[i.second])
        {
            total_benefit+=(capacity/weight[i.second])*benefit[i.second];
            R[i.second]=(capacity/weight[i.second]);
            capacity=0;
            break;
        }
    }
    return total_benefit;
}
int main()
{
    ifstream ip;
    ip.open("knapsack.txt");
    int n;
    ip>>n;
    vec_1D weight(n),benefit(n),ratio(n);
    cout<<"P/W: ";
    for(int i=0;i<n;i++)
    {
        ip>>weight[i]>>benefit[i];
        double k=benefit[i]/weight[i];
        Ratio.push_back({-k,i});
        cout<<k<<" ";
    }
    Ratio=Merge_Sort(0,n-1,Ratio);
    newl;newl;
    double capacity;
    ip>>capacity;
    double value=Frac_Knapsack(capacity,weight,benefit);
    cout<<"Total Profit: "<<value;newl;newl;
    cout<<"Ratio: ";
    for(int i=0;i<n;i++)
    {
        cout<<R[i]<<" ";
    }
    newl;
}
