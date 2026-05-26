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
class Circuit
{
    private:
    int real;
    int img;
    str s="z0";
    int v1,v2;
    public:
    Circuit()
    {
        s[1]++;
    }
    Circuit(int x,int y)
    {
        real=x;
        img=y;
        s[1]++;
    }
    Circuit operator/(const Circuit &p)
    {
        v1=(100*p.real)-((-p.img)*50);
        v2=(100*(-p.img))+(50*p.real);
    }
    void Dispaly()
    {
        cout<<s<<"="<<real;
        if(img>0)
        {
            cout<<"+"<<"j"<<img;newl;
        }
        else
        {
            cout<<"-"<<"j"<<-(img);newl;
        }
    }
    void current()
    {
        cout<<"I"<<s[1]<<"=";
        cout<<v1;
        if(v2>0)
        {
            cout<<"+"<<"j"<<v2;newl;
        }
        else
        {
            cout<<"-"<<"j"<<-v2;newl;
        }
    }
};
int main()
{
    Circuit z1(3,4),z2(4,-3),z3(0,6);
    z1.operator/(z1);z2.operator/(z2);z3.operator/(z3);
    z1.current();z2.current();z3.current();
}
