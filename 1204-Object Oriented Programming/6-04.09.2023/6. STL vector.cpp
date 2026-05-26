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
int f(int x){if(x==1){return 1;}return x*f(x-1);}
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
void Display(vector<int>&A)
{
    for(int i:A)
    {
        cout<<i<<" ";
    }
    newl;
}
int main()
{
    vector<int>ax;
    int A[10]={5,9,4,7,6,8,10,15,10,14};
    // i)
    for(int i=0;i<10;i++)
    {
        ax.push_back(A[i]);
    }
    Display(ax);
    // ii)
    ax.pop_back();
    ax.pop_back();Display(ax);
    // iii)
    auto it=ax.begin();
    advance(it,3);
    ax.insert(it,20);Display(ax);
    // iv)
    cout<<ax.front()<<endl;
    // v)
    cout<<ax.back()<<endl;
    // vi)
    cout<<ax.at(4)<<endl;
    // vii)
    auto i=ax.begin();
    advance(i,6);
    ax.erase(i);Display(ax);
    // viii)
    cout<<ax.size()<<endl;
    // ix)
    cout<<ax.capacity()<<endl;
    // x)
    ax.reserve(5);
    cout<<ax.size()<<endl;
    // xi)
    ax.shrink_to_fit();
    cout<<ax.capacity()<<endl;
    // xii)
    ax.resize(5);
    Display(ax);
    // xiii)
    ax.clear();
    cout<<ax.size()<<endl;
}
