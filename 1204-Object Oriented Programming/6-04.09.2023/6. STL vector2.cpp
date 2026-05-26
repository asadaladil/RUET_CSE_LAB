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
#define clr system("cls");
vector<int>ax;
void menu()
{
    cout<<"**** Main Menu ****";
    cout<<"1. Insert";
    cout<<"2. Delete";
    cout<<"3. Search";
    cout<<"4. Display list";
    cout<<"5. Exit";
    cout<<"Enter your option:";
}
void sub_menu()
{
    cout<<"**** Insert Sub Menu ****";
    cout<<"1. Insert at First";
    cout<<"2. Insert at Last";
    cout<<"3. Insert Before";
    cout<<"4. Insert After";
    cout<<"5. Exit";
    cout<<"Enter your option";
}
void insert(int x)
{
    if(x==1){}}
    else if(x==2){}
}
int main()
{
    menu();
    while(1)
    {
        int i;
        cin>>i;
        if(i==1)
        {
            clr
            sub_menu();
            int x;
            cin>>x;
            insert(x);
        }
    }
}
