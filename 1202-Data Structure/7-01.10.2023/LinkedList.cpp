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
ll f(ll x){if(x<=1){return 1;}return x*f(x-1);}
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

class node
{
    public:
    int data;
    node *next;
};

class LinkedList
{
    public:
    node *head;
    node *tail;
    int size;
    LinkedList()
    {
        size=0;
    }
    void insert_at_head(int n)
    {
        node *a=Create_new_node(n);
        if(size==0)
        {
            head=a;
            tail=a;
            head->next=NULL;
            tail->next=NULL;
            size++;
            return;
        }
        a->next=head;
        head=a;
        size++;
    }
    void insert_at_tail(int n)
    {
        node *a=Create_new_node(n);
        if(size==0)
        {
            head=a;
            tail=a;
            head->next=NULL;
            tail->next=NULL;
            size++;
            return;
        }
        tail->next=a;
        tail=a;
        size++;
    }
    void print()
    {
        node *a=head;
        while(a!=NULL)
        {
            cout<<a->data<<" ";
            a=a->next;
        }
    }
    void Delete(int n)
    {
        node *a=head;
        while(a!=NULL)
        {
            if(a->next!=NULL&&a->next->data==n)
            {
                break;
            }
            a=a->next;
        }   
        if(a==NULL)
        {
            cout<<"No element";
            return;
        } 
        node *b=a->next;
        a->next=b->next;
        b->next=NULL;
    }
    int Size()
    {
        return size;
    }
    private:
    node* Create_new_node(int n)
    {
        node *newnode=new node;
        newnode->data=n;
        newnode->next=NULL;
        return newnode;
    }
};
int main()
{
    LinkedList l;
    for(int i=1;i<=20;i++)
    {
        l.insert_at_tail(i);
    }
    l.Delete(21);
    l.print();
    newl;
    cout<<l.Size();
}
