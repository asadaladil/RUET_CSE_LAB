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
#define yes_or_no cout<<"YES\n":cout<<"NO\n"
#define yess cout<<"YES\n"
#define noo cout<<"NO\n"
#define endl "\n"
#define newl cout<<endl

ll step=0;
int Linear_Search(vector<int>A,int find,int i)
{
    int n=A.size();
    if(i==n)
    {
        step++;
        return -1;
    }
    if(A[i]==find)
    {
        step++;
        return i;
    }
    step++;
    return Linear_Search(A,find,i+1);
}

int Binary_Search(vector<int>A,int find,int low,int high)
{
    if(low==high)
    {
        step++;
        if(A[low]==find)
        {
            step++;
            return low;
        }
        return -1;
    }
    step++;
    int mid=(low+high)/2;
    if(A[mid]==find)
    {
        step++;
        return mid;
    }
    else if(A[mid]<find)
    {
        step++;
        return Binary_Search(A,find,mid+1,high);
    }
    else
    {
        step++;
        return Binary_Search(A,find,low,mid-1);
    }
}
int main()
{
    srand(time(0));
    vector<int>A[8],B={2000,5000,8000,10000,12000,15000,18000,20000};
    for(int i=0;i<8;i++)
    {
        ifstream ip;
        ip.open("input1.txt");
        for(int j=0;j<B[i];j++)
        {
            int x;
            ip>>x;
            A[i].push_back(x);
        }
        ip.close();
    }
    ofstream op;
    op.open("output.txt");
    for(int i=0;i<8;i++)
    {
        op<<"Total value: ";
        op<<B[i]<<"\n";
        int a=rand();
        op<<"Linear Search: \n";
        op<<"Position: "<<Linear_Search(A[i],a,0)<<" Total Steps: "<<step<<"\n";
        step=0;
        op<<"Binary Search: \n";
        op<<"Position: "<<Binary_Search(A[i],a,0,A[i].size())<<" Total Steps: "<<step<<"\n\n\n";
        step=0;
    }
}
