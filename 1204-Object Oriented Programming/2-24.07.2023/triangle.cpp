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

class Triangle
{
private:
    float first_arm;
    float second_arm;
    float third_arm;
    bool right;
public:
    Triangle()
    {
        first_arm=0;
        second_arm=0;
        third_arm=0;
    }
    Triangle(float a,float b, float c)
    {
        if(a+b<=c||a+c<=b||b+c<=a)
        {
            cout<<"Error trinagle\n";
            return;
        }
        a=abs(a);b=abs(b);c=abs(c);
        first_arm=a;
        second_arm=b;
        third_arm=c;
        if(((a*a)+(b*b))==(c*c)||((a*a)+(c*c))==(b*b)||((b*b)+(c*c))==(a*a))
        {
            right=true;
        }
        else
        {
            right=false;
        }
    }
    void set_value(float a,float b, float c)
    {
        if(a+b<=c||a+c<=b||b+c<=a)
        {
            cout<<"Error trinagle\n";
            
        }
        else
        {
            first_arm=abs(a);
            second_arm=abs(b);
            third_arm=abs(c);
        }
    }
    void get_perimetre()
    {
        cout<<"perimetre-> "<<(first_arm+second_arm+third_arm)<<endl;
    }
    void get_area()
    {
        float s=(first_arm+second_arm+third_arm)/2;
        float ss=s*(s-first_arm)*(s-second_arm)*(s-third_arm);
        cout<<"Area-> "<<sqrt(ss)<<endl;
    }
    void is_right_angle()
    {
        if(right)
        {
            cout<<"it is a right angle triangle\n";
        }
        else
        {
            cout<<"it is not a right angle triangle\n";
        }
    }
    
};
int main()
{
    Triangle t1,t2,t3;
    t1.set_value(6.58,5.36,10.79);
    t1.get_perimetre();
    t1.get_area();
    t1.is_right_angle();  
    t2.set_value(3.00,4.00,5.00);
    t2.is_right_angle();  
}
