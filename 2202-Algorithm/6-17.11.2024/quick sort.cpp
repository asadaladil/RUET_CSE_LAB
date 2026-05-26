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
using vec_1D=vector<int>;
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

ll step;
void print(vec_1D &A)
{
    for(int i:A)
    {
        cout<<i<<" ";
    }
}
int Partition(int l,int h, vec_1D &A)
{
    int pivot=A[l];
    int i=l,j=h;
    step++;
    while(i<j)
    {
        do
        {
            i++;
        }while(A[i]<=pivot);
        do
        {
            j--;
        }while(A[j]>pivot);
        if(i<j)
        {
            step++;
            swap(A[i],A[j]);
        }
        step++;
    }
    swap(A[l],A[j]);step++;
    return j;
}
vec_1D Merge(vec_1D &left,vec_1D &right)
{
    int n=left.size()+right.size(),l=0,r=0;
    vec_1D ans(n);
    step++;
    for(int i=0;i<n;i++)
    {
        step++;
        if(l!=int(left.size())&&(left[l]<=right[r] || r==int(right.size())))
        {
            ans[i]=left[l];
            l++;
            step++;
        }
        else if(r!=int(right.size())&&(right[r]<=left[l] || l==int(left.size())))
        {
            ans[i]=right[r];
            r++;
            step++;
        }
    }
    step++;
    return ans;
}
vec_1D Quick_Sort(int l,int h,vec_1D &list)
{
    if(l>=h)
    {
        step++;
        return {list[l]};
    }
    int j=Partition(l,h,list);
    vec_1D left=Quick_Sort(l,j,list);step++;
    vec_1D right=Quick_Sort(j+1,h,list);step++;
    return Merge(left,right);
}
int main()
{
    ofstream op;
    op.open("output.txt");
    op<<"Array Size--->Step Count\n";
    vec_1D N={1000,2000,5000,10000};
    for(int i=0;i<4;i++)
    {
        step=0;
        ifstream ip;
        ip.open("input.txt");
        vec_1D list(N[i]);
        for(int j=0;j<N[i];j++)
        {
            ip>>list[j];
        }
        list=Quick_Sort(0,N[i]-1,list);
        op<<N[i]<<"------->"<<step<<"\n";
        //print(list);
        ip.close();
    }
}
