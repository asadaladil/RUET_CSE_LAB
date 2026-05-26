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
#define enter getchar();getchar();
void menu()
{
    cout<<"**** Main Menu ****\n";
    cout<<"1. Insert\n";
    cout<<"2. Delete\n";
    cout<<"3. Search\n";
    cout<<"4. Display list\n";
    cout<<"5. Exit\n";
    cout<<"Enter your option:\n";
}
void sub_menu()
{
    cout<<"**** Insert Sub Menu ****\n";
    cout<<"1. Insert at First\n";
    cout<<"2. Insert at Last\n";
    cout<<"3. Insert Before\n";
    cout<<"4. Insert After\n";
    cout<<"5. Exit\n";
    cout<<"Enter your option:\n";
}
class Vector
{
    private:
    vector<int>ax;
    public:
    Vector()
    {

    }
    void Insert(int x)
    {
        clr
        sub_menu();
        int a;cin>>a;
        if(a==1){insert_first(x);}
        else if(a==2){Insert_last(x);}
        else if(a==3)
        {
            int b;cin>>b;
            Insert_before(b,x);
        }
        else if(a==4)
        {
            int b;cin>>b;
            Insert_after(b,x);
        }
        else
        {
            return;
        }
    }
    void insert_first(int x)
    {
        vector<int>::iterator ptr=ax.begin();
        ax.insert(ptr,x);
    }
    void Insert_last(int x)
    {
        ax.push_back(x);
    }
    void Insert_before(int x,int y)
    {
        auto it=ax.begin();
        while(*it!=x)
        {
            it++;
        }
        if(it==ax.end())
        {
            cout<<"NO ELEMENT FOUND OF"<<y;
            newl;
            return;
        }
        it--;
        ax.insert(it,y);
    }
    void Insert_after(int x,int y)
    {
        auto it=ax.begin();
        while(*it!=x)
        {
            it++;
        }
        if(it==ax.end())
        {
            cout<<"NO ELEMENT FOUND OF"<<y;
            newl;
            return;
        }
        it++;
        if(it==ax.end())
        {
            ax.push_back(y);
            return;
        }
        ax.insert(it,y);
    }
    void Display()
    {
        for(int i:ax)
        {
            cout<<i<<" ";
        }
        newl;
    }
    void Delete(int x)
    {
        auto it=ax.begin();
        while(*it!=x)
        {
            it++;
        }
        if(it==ax.end())
        {
            cout<<"NO ELEMENT FOUND OF"<<x;
            newl;
            return;
        }
        ax.erase(it);
    }
    void Search(int x)
    {
        for(int i=0;i<ax.size();i++)
        {
            if(ax[i]==x)
            {
                cout<<"INDEX->"<<i;
                newl;
                return;
            }
        }
        cout<<"NO ELEMENT FOUND\n";
    }
};
int main()
{
    menu();
    Vector v;
    while(1)
    {
        int i;
        cin>>i;
        if(i==1)
        {
            int a;cin>>a;
            v.Insert(a);
            enter
            clr
            main();
        }
        else if(i==2)
        {
            int x;cin>>x;
            v.Delete(x);
            enter
            clr
            main();
        }
        else if(i==3)
        {
            int x;
            cin>>x;
            v.Search(x);
            enter
            clr
            main();
        }
        else if(i==4)
        {
            v.Display();
            enter
            clr
            main();
        }
        else
        {
            break;
        }
    }
}
