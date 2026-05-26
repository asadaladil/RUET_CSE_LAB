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
#define vary_perm(x) next_permutation(x.begin(),x.end())
#define yes_or_no cout<<"YES\n":cout<<"NO\n"
#define yess cout<<"YES\n"
#define noo cout<<"NO\n"
#define endl "\n"
#define newl cout<<endl
int main()
{
    str s;
    int q;cin>>q;
    cin>>s;
    int a=0,b=0,c=0,d=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
            a=1;
        }
        else if(s[i]>='a'&&s[i]<='z')
        {
            b=1;
        }
        else if(s[i]>='0'&&s[i]<='9')
        {
            c=1;
        }
        else if(s[i]=='!'||s[i]=='@'||s[i]=='#'||s[i]=='$'||s[i]=='%'||s[i]=='^'||s[i]=='&'||s[i]=='*'||s[i]=='('||s[i]==')'||s[i]=='-'||s[i]=='+')
        {
            d=1;
        }
    }
    if(s.size()<6)
    {
        if(a==1&&b==1&&c==1&&d==1)
        {
            cout<<6-s.size()<<endl;
        }
        else if((4-a-b-c-d)+s.size()>=6)
        {
            cout<<(4-a-b-c-d)<<endl;
        }
        else
        {
            cout<<6-s.size()<<endl;
        }
    }
    else
    {
        cout<<4-(a+b+c+d)<<endl;
    }
}

