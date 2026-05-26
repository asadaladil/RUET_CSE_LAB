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
#define yes_or_no cout<<"YES":cout<<"NO"
#define yess cout<<"YES\n"
#define noo cout<<"NO\n"
#define endl "\n"
#define newl cout<<endl
void Display(list<int>&li)
{
    auto i=li.begin();
    auto j=li.end();
    while(i!=j)
    {
        cout<<*i<<" ";
        i++;
    }
}
void DisplayRev(list<int>&li)
{
    auto i=li.rbegin(),j=li.rend();
    while(i!=j)
    {
        cout<<*i<<" ";
        i++;
    }
}
int Even_count(list<int>&li)
{
    int x=0;
    for(auto i:li)
    {
        if(ev(i))
        {
            x++;
        }
    }
    return x;
}
bool is_odd(int x)
{
    return od(x);
}
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int A[]={10,64,25,36,78,64,69,70,64,67};
    list<int>li;
    // i)
    for(int i=1;i<=8;i++)
    {
        li.push_back(A[i-1]);
    }
    // ii)
    li.push_front(A[8]);
    li.push_front(A[9]);
    // iii)
    Display(li);newl;
    // iv)
    DisplayRev(li);newl;
    // v)
    cout<<li.front();newl;
    // vi)
    cout<<li.back();newl;
    // vii)
    li.pop_front();Display(li);newl;
    // viii)
    li.pop_back();Display(li);newl;
    // ix)
    find(li.begin(),li.end(),78)!=li.end()?yes_or_no;cout<<" ";
    find(li.begin(),li.end(),100)!=li.end()?yes_or_no;newl;
    // x)
    auto x=li.begin();advance(x,2);
    li.insert(x,100);Display(li);newl; // after 10
    // xi)
    auto y=li.begin();advance(y,4);
    li.insert(y,50);Display(li);newl; // before 25
    // xii)
    cout<<count(li.begin(),li.end(),64);newl;
    // xiii)
    cout<<Even_count(li);newl;
    // xiv)
    auto z=li.begin();advance(z,9);
    li.erase(z);Display(li);newl;
    // xv)
    for(int i=1;i<=4;i++)
    {
        li.erase(li.begin());
    }
    Display(li);newl;
    // xvi)
    auto b=remove(li.begin(),li.end(),78);
    li.erase(b,li.end());
    Display(li);newl;
    // xvii)
    auto a=remove_if(li.begin(),li.end(),is_odd);
    li.erase(a,li.end());
    Display(li);newl;
    // xviii)
    list<int>B={15,25,51,45,60,80,64};
    li.assign(B.begin(),B.end());
    Display(li);newl;
    // xix) 
    li.assign(begin(A),end(A));
    Display(li);newl;
    // xx)
    li.sort();Display(li);newl;
    // xxi)
    auto it=unique(li.begin(),li.end());
    li.erase(it,li.end());
    Display(li);newl;

    li.sort(cmp);
    Display(li);
}
