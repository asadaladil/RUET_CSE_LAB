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
int main()
{
    cout<<"Total member of A set-> ";
    int a;
    cin>>a;
    cout<<"Total member of set B-> ";
    int b;
    cin>>b;
    set<int>A,B;
    cout<<"Taking value of A\n";
    for(int i=0;i<a;i++)
    {
        int x;cin>>x;
        A.insert(x);
    }
    cout<<"Taking value of B\n";
    for(int i=0;i<b;i++)
    {
        int x;
        cin>>x;
        B.insert(x);
    }
    set<int>D;
    bool flag=true;
    for(int i:A)
    {
        int F=i*i*i+i*i-i-1;
        if(B.find(F)==B.end())
        {
            flag=false;
            break;
        }
        D.insert(F);
    }
    if(!flag)
    {
        cout<<"It is not a function";
        return 0;
    }
    cout<<"One-to-One-> ";
    A.size()==D.size()?yes_or_no;
    cout<<"Onto-> ";
    D==B?yes_or_no;
    
}
