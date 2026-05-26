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
vec_1D Merge_Sort(vec_1D arr)
{
    int L=arr.size();
    if(L==1)
    {
        step++;
        return arr;
    }
    int n=L/2; step++;
    vec_1D left,right;
    step++;
    for(int i=0;i<n;i++)
    {
        left.push_back(arr[i]);step+=2;
    }
    step++;

    step++;
    for(int i=n;i<L;i++)
    {
        right.push_back(arr[i]);step+=2;
    }
    step++;
    left=Merge_Sort(left);step++;
    right=Merge_Sort(right);step++;
    vec_1D merge;
    int l=0,r=0;
    step++;
    for(int i=0;i<L;i++)
    {
        step++;
        if(r==int(right.size()) || left[l]<=right[r])
        {
            merge.push_back(left[l]);step+=2;
            l++;
            continue;
        }
        merge.push_back(right[r]);step++;
        r++;
    }
    step++;
    return merge;
}

vec_1D Quick_Sort(vec_1D arr)
{
    int L=0,h=arr.size();
    if (h<=1)
    {
        step++;
        return arr;
    }
    int p=(L+h)/2;step++;
    vec_1D left,right;
    step++;
    for(int i=0;i<h;i++)
    {
        step++;
        if(arr[i]<=arr[p]&&i!=p)
        {
            left.push_back(arr[i]);step+=2;
        }
        else if(i!=p)
        {
            right.push_back(arr[i]);step+=2;
        }
    }
    step++;
    left=Quick_Sort(left);step++;
    right=Quick_Sort(right);step++;
    vec_1D quick;
    step++;
    for(int i=0;i<int(left.size());i++)
    {
        step++;
        quick.push_back(left[i]);step++;
    }
    step++;
    quick.push_back(arr[p]);step++;
    step++;
    for(int i=0;i<int(right.size());i++)
    {
        step++;
        quick.push_back(right[i]);step++;
    }
    step++;
    return quick;
}
int main()
{
    vec_1D list={1000,2500,5000,7500,10000,12500,15000,17500,20000};
    ofstream op;
    op.open("output.txt");
    op<<"Total Number\tMerge Sort Steps\tQuick Sort Steps\n";
    for(int i=0;i<9;i++)
    {
        ifstream ip;
        ip.open("input.txt");
        vec_1D merge(list[i]),quick(list[i]);
        for(int j=0;j<list[i];j++)
        {
            ip>>merge[j];
            quick[j]=merge[j];
        }
        ip.close();
        op<<"  "<<list[i]<<"\t\t";
        merge=Merge_Sort(merge);
        op<<"\t\t\t"<<step<<"\t";
        step=0;
        quick=Quick_Sort(quick);
        op<<"\t\t\t"<<step<<"\t\n";
        step=0;
    }
    op<<"\n";
}
// for(int j=0;j<list[i];j++)
        // {
        //     cout<<quick[j]<<" ";
        // }
        // newl;
