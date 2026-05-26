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
#define yes_or_no cout<<"YES\n":cout<<"NO\n"
#define yess cout<<"YES\n"
#define noo cout<<"NO\n"
#define endl "\n"
#define newl cout<<endl
class triangle
{
    private:
    int a1,a2,a3;
    float area()
    {
        int s=(a1+a2+a3)/2;
        int m=s*(s-a1)*(s-a2)*(s-a3);
        float A=float(sqrt(m));
        return A;
    }
    public:
    triangle()
    {

    }
    triangle(int a,int b,int c)
    {
        a1=a;a2=b;a3=c;
    }
    triangle(triangle &p)
    {
        this->a1=p.a1;
        this->a2=p.a2;
        this->a3=p.a3;
    }
    void set_len(int a,int b,int c)
    {
        a1=a;a2=b;a3=c;
    }
    void get_area()
    {
        cout<<"Area of triangle-->";
        cout<<area();
        newl;
    }
    ~triangle()
    {

    }
};
class rectangle
{
    private:
    int a1,a2;
    int area()
    {
        return a1*a2;
    }
    public:
    rectangle()
    {

    }
    rectangle(int a,int b)
    {
        a1=a;a2=b;
    }
    rectangle(rectangle &p)
    {
        this->a1=p.a1;
        this->a2=p.a2;
    }
    void set_len(int a,int b)
    {
        a1=a;a2=b;
    }
    void get_area()
    {
        cout<<"Area of rectangle-->";
        cout<<area();
        newl;
    }
    ~rectangle()
    {
        
    }
};
int main()
{
    triangle t1;
    t1.set_len(3,4,5);
    t1.get_area();
    rectangle r1;
    r1.set_len(10,25);
    r1.get_area();
    
}
