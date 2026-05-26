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
#define yes_or_no cout<<"YES ":cout<<"NO "
#define yess cout<<"YES\n"
#define noo cout<<"NO\n"
#define endl "\n"
#define newl cout<<endl
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
class List
{
    private:
    list<int>ax;
    public:
    List()
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
        if(ax.size()==0)
        {
            cout<<"NO ELEMENT\n";
            return;
        }
        auto i=ax.begin();
        auto j=ax.end();
        while(i!=j)
        {
            cout<<*i<<" ";
            i++;
        }
        newl;
    }
    void DisplayRev()
    {
        if(ax.size()==0)
        {
            cout<<"NO ELEMENT\n";
            return;
        }
        auto i=ax.rbegin(),j=ax.rend();
        while(i!=j)
        {
            cout<<*i<<" ";
            i++;
        }
        newl;
    }
    int Front_show()
    {
        if (ax.size()==0)
        {
            cout<<"NO ELEMENT";newl;
            return 0;
        }
        return ax.front();   
    }
    void Back_show()
    {
        if (ax.size()==0)
        {
            cout<<"NO ELEMENT";newl;
            return ;
        }
        cout<<"Rear Element: "<<ax.back();newl;
    }
    int Find(int x)
    {
        int y=(ax.begin(),ax.end(),x);
        return y;
    }
    void Insert(int i,int x)
    {
        auto it=ax.begin();advance(it,i);
        ax.insert(it,x);Display();
    }
    void Count(int x)
    {
        if(Find(x)==0)
        {
            cout<<x<<"is not found\n";return;
        }
        cout<<count(ax.begin(),ax.end(),x);newl;
    }
    void Even()
    {
        cout<<Even_count(ax);newl;
    }
    void Delete(int i)
    {
        auto z=ax.begin();advance(z,i);
        ax.erase(z);Display();
    }
    void Sort()
    {
        ax.sort();
    }
    void Unique()
    {
        auto it=unique(ax.begin(),ax.end());
        ax.erase(it,ax.end());
        Display();
    }
    void Remove(int x)
    {
        auto b=remove(ax.begin(),ax.end(),x);
        ax.erase(b,ax.end());
        Display();
    }
    void Remove_If()
    {
        auto a=remove_if(ax.begin(),ax.end(),is_odd);
        ax.erase(a,ax.end());
        Display();
    }
    void Assign(list<int>B)
    {
        ax.assign(B.begin(),B.end());
        Display();
    }
    void Array_assign(int A[],int n)
    {
        ax.assign(A,A+n);
    }
};
int main()
{
    int A[]={10,64,25,36,78,64,69,70,64,67};
    int n=10;
    List li;
    // i)
    for(int i=1;i<=8;i++)
    {
        li.Push_Back(A[i-1]);
    }
    li.Display();
    // ii)
    li.Push_Front(A[8]);li.Push_Front(A[9]);
    li.Display();
    // iii)
    li.Display();
    // iv)
    li.DisplayRev();
    // v)
    cout<<li.Front_show();newl;
    // vi)
    li.Back_show();
    // vii)
    li.Pop_Front();li.Display();
    // viii)
    li.Pop_Back();li.Display();
    // ix)
    li.Find(64)?yes_or_no;li.Find(50)?yes_or_no;
    // x)
    li.Insert(2,75);
    // xi)
    li.Insert(4,110);
    // xii)
    li.Count(64);
    // xiii)
    li.Even();
    // xiv)
    li.Delete(36);
    // xv)
    for(int i=1;i<=4;i++)
    {
        li.Delete(li.Front_show());
    }
    // xvi)
    li.Remove(70);
    // xvii)
    li.Remove_If();
    // xviii)
    list<int>B={15,25,51,45,60,80,64};
    li.Assign(B);
    // xix)
    li.Array_assign(A,n);
    // xx)
    li.Sort();li.Display();
    // xxi)
    
}
