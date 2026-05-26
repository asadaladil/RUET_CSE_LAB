// AuB,A inter B, A-B, B-A, A^B
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

unordered_map<int,int>C,D;
void Union()
{
    cout<<"A union B->";
    for(int i=0;i<1000;i++)
    {
        if(C[i]||D[i])
        {
            cout<<i<<" ";
        }
    }
    newl;
}
void Intersection()
{
    cout<<"A intersection B->";
    for(int i=0;i<1000;i++)
    {
        if(C[i]==1&&D[i]==1)
        {
            cout<<i<<" ";
        }
    }
    newl;
}
void Exclusive()
{
    cout<<"A symmetric difference B->";
    for(int i=0;i<1000;i++)
    {
        if(C[i]+D[i]==1)
        {
            cout<<i<<" ";
        }
    }
    newl;
}
void Difference(unordered_map<int,int>&A,unordered_map<int,int>&B)
{
    for(int i=0;i<1000;i++)
    {
        if(A[i]==1)
        {
            if(B[i]!=1)
            {
                cout<<i<<" ";
            }
            
        }
    }
    newl;
}
int main()
{
    cout<<"Total Elements of A Set-> ";
    int a;
    cin>>a;
    cout<<"Total Elements of B Set-> ";
    int b;
    cin>>b;
    vector<int>A,B;
    cout<<"Taking A Set\n";
    for(int i=0;i<a;i++)
    {
        int x;
        cin>>x;
        if(C[x]==0)
        {
            A.push_back(x);
            C[x]++;
        }
    }
    cout<<"Taking B Set\n";
    for(int i=0;i<b;i++)
    {
        int x;
        cin>>x;
        if(D[x]==0)
        {
            B.push_back(x);
            D[x]++;
        }
    }
    Union();
    Intersection();
    Exclusive();
    cout<<"A-B->";
    Difference(C,D);
    cout<<"B-A->";
    Difference(D,C);
    
}
