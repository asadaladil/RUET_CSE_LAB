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
using Pvec_1D=vector<pair<double,ll>>;
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

Pvec_1D high;
vec_1D job(100);
vec_1D job_sec(100);
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
double Job_Sequencing(vec_1D profit,vector<int>deadline,int slot)
{
    double total_benefit=0.0;
    double time=0;
    for(auto i:high)
    {
        int temp=deadline[i.second];
        if (job_sec[temp]==0)
        {
            job[i.second]=1;
            job_sec[temp]=i.second+1;
            total_benefit+=profit[i.second];
            time++;
        }
        else
        {
            temp--;
            while(temp>0)
            {
                if(job_sec[temp]==0)
                {
                    job[i.second]=1;
                    job_sec[temp]=i.second+1;
                    total_benefit+=profit[i.second];
                    time++;
                    break;
                }
                temp--;
            }
        }
        if(time==slot)
        {
            break;
        }
    }
    return total_benefit;
}
int main()
{
    freopen("job.txt","r",stdin); 
    int n;
    cin>>n;
    vec_1D profit(n);
    vector<int>deadline(n);
    cout<<"(J,D): ";
    int slot=-10;
    for(int i=0;i<n;i++)
    {
        cin>>profit[i];
        high.push_back({-profit[i],i});
    }
    for(int i=0;i<n;i++)
    {
        cin>>deadline[i];
        slot=max(slot,deadline[i]);
        cout<<"("<<profit[i]<<","<<deadline[i]<<") ";
    }
    high=Merge_Sort(0,n-1,high);
    newl;newl;
    double value=Job_Sequencing(profit,deadline,slot);
    cout<<"Total Profit: "<<value;newl;newl;
    cout<<"Job: ";
    for(int i=0;i<n;i++)
    {
        cout<<job[i]<<" ";
    }
    newl;newl;
    cout<<"Job Sequence: ";
    for(int i=1;i<=slot;i++)
    {
        cout<<job_sec[i]<<" ";
    }
    newl;
}
