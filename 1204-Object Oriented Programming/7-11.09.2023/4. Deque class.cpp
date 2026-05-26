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
class Deque
{
    private:
    deque<int>ax;
    public:
    Deque()
    {

    }
    void Push_Back(int x)
    {
        ax.P_B(x);
    }
    void Push_Front(int x)
    {
        ax.P_F(x);
    }
    void Pop_Back()
    {
        ax.p_b();
    }
    void Pop_Front()
    {
        ax.p_f();
    }
    void Display()
    {
        if (ax.size()==0)
        {
            cout<<"NO ELEMENT";newl;
            return;
        }
        cout<<"Front Element: "<<ax.front();newl;
        cout<<"Rear Element: "<<ax.back();newl;
    }

};
void menu()
{
    cout<<"**** Dueue Menu ****\n";
    cout<<"   "<<"1. Enqueue (Front)\n";
    cout<<"   "<<"2. Enqueue (Back)\n";
    cout<<"   "<<"3. Dequeue (Front)\n";
    cout<<"   "<<"4. Dequeue (Back)\n";
    cout<<"   "<<"5. Display\n";
    cout<<"   "<<"6. Exit\n";
    cout<<"      "<<"Enter your option: ";
}
int main()
{
    Deque dq;
    menu();
    while(1)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            cout<<"Enter Value: ";
            int x;cin>>x;
            dq.Push_Front(x);
            clr
            menu();
        }
        else if(a==2)
        {
            cout<<"Enter Value: ";
            int x;cin>>x;
            dq.Push_Back(x);clr
            menu();
        }
        else if(a==3)
        {
            dq.Pop_Front();clr
            menu();
        }
        else if(a==4)
        {
            dq.Pop_Back();clr
            menu();
        }
        else if(a==5)
        {
            dq.Display();
            getchar();getchar();
            clr
            menu();
        }
        else 
        {
            break;
        }
    }
}
