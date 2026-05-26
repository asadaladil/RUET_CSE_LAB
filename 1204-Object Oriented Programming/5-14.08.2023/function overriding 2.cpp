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
#define reverse(x) reverse(x.begin(),x.end())
#define vary(A,x,y,n) transform(A.begin()+x,A.begin()+y,A.begin()+x,[](int a){return a+n;})
#define yes_or_no cout<<"YES\n":cout<<"NO\n"
#define yess cout<<"YES\n"
#define noo cout<<"NO\n"
#define endl "\n"
#define newl cout<<endl
class A
{
    public:
    virtual void Print()
    {
        cout<<"Inside Print() of class A"<<endl;
    }
};
class B:public A
{
    public:
    virtual void Print()
    {
        cout<<"Inside Print() of class B"<<endl;
    }
};
int main()
{
    /*// i)
    A a;
    //a.Print();
    // ii)
    B b;
    //b.Print();
    // iii)
    A *p;
    p=&a;
    //p->Print();
    // iv)
    p=&b;
    p->Print();*/
    
    
    //After writing virtual:::::::
    // i)
    A a;
    //a.Print();
    // ii)
    B b;
    //b.Print();
    // iii)
    A *p;
    //p=&a;
    //p->Print();
    // iv)
    p=&b;
    p->Print();
}
