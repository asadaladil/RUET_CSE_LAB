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

ll step=0;
vec_1D Max_Min(int a,int b,vec_1D A)
{
    if (b-a<=1)
    {
        step++;
        return {max(A[a],A[b]),min(A[a],A[b])};
    }
    else
    {
        vec_1D mx1_mn1=Max_Min(a,(a+b)/2,A);step++;
        vec_1D mx2_mn2=Max_Min((a+b)/2+1,b,A);step++;
        step++;
        return {max(mx1_mn1[0],mx2_mn2[0]),min(mx1_mn1[1],mx2_mn2[1])};
    }
}
vec_1D Brute_force_max_min(vec_1D A)
{
    vec_1D ans={A[0],A[0]};step++;
    step++;
    for (int i=0;i<int(A.size());i++)
    {
        if (A[i]>ans[0])
        {
            ans[0]=A[i];step+=2;
        }
        if (A[i]<ans[1])
        {
            ans[1]=A[i];step+=2;
        }
        step++;
    }
    step++;
    return ans;
}
int main()
{
    vec_1D list={1000,2500,5000,7500,10000,12500,15000,17500,20000};
    cout<<"Recursive Form";newl;
    for(int i=0;i<9;i++)
    {
        ifstream ip;
        ip.open("input.txt");
        vec_1D data(list[i]);
        for(int j=0;j<list[i];j++)
        {
            ip>>data[j];
        }
        ip.close();
        vec_1D mx_mn=Max_Min(0,list[i]-1,data);
        cout<<mx_mn[0]<<" "<<mx_mn[1]<<" "<<step;newl;
        step=0;
    }
    newl;
    cout<<"Brute Force Form";newl;
    for(int i=0;i<9;i++)
    {
        ifstream ip;
        ip.open("input.txt");
        vec_1D data(list[i]);
        for(int j=0;j<list[i];j++)
        {
            ip>>data[j];
        }
        ip.close();
        vec_1D mx_mn=Brute_force_max_min(data);
        cout<<mx_mn[0]<<" "<<mx_mn[1]<<" "<<step;newl;
        step=0;
    }
}
