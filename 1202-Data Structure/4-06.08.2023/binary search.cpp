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
#include<conio.h>
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
int main()
{
    vector<int>A={6,8,6,9,10,1,5,7,12,15,100,52,40,47,50,55};
    int n=A.size();
    vector<pair<int,int>>ab(n);
    for(int i=0;i<n;i++)
    {
        ab[i].first=A[i];ab[i].second=i+1;
        cout<<A[i]<<" ";
    }
    newl;
    while(1)
    {
        int b=0;
        for(int i=0;i<n-1;i++)
        {
            if(ab[i].first>ab[i+1].first)
            {
                swap(ab[i],ab[i+1]);
            }
            else
            {
                b++;
            }
        }
        if(b==n-1)
        {
            break;
        }
    }
    int a;
    cin>>a;
    int lb=0,up=n;
    int mid=(lb+up)/2;
    while(1)
    {
        if(ab[mid].first<a)
        {
            lb=mid;
            mid=(lb+up)/2;
        }
        else if(ab[mid].first==a)
        {
            cout<<ab[mid].second;
            break;
        }
        else if(ab[mid].first>a)
        {
            up=mid;
            mid=(lb+up)/2;
        }
        else
        {
            cout<<"Not found\n";
            break;
        }
    }
    

}
