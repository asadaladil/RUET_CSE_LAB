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
#include <bits/stdc++.h>
using namespace std;
#define _easy_                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long long int
#define str string
#define ev(x) x % 2 == 0
#define od(x) x % 2 == 1
#define mod0(x, y) x % y == 0
#define P_B push_back
#define p_b pop_back
#define P_F push_front
#define p_f pop_front
#define pi 3.141592654
ll f(ll x)
{
    if (x <= 1)
    {
        return 1;
    }
    return x * f(x - 1);
}
#define __lcm(x, y) (x * y) / __gcd(x, y)
#define A_sort(x) sort(x.begin(), x.end())
#define D_sort(x) sort(x.rbegin(), x.rend())
#define Reverse(x) reverse(x.begin(), x.end())
#define Vary(A, x, y, n) transform(A.begin() + x, A.begin() + y, A.begin() + x, [](int a) { return a + n; })
#define Vary_perm(x) next_permutation(x.begin(), x.end())
#define yes_or_no cout << "YES\n" : cout << "NO\n"
#define yess cout << "YES\n"
#define noo cout << "NO\n"
#define endl "\n"
#define newl cout << endl

void tower(int n, char x, char y, char z)
{
    if (n == 1)
    {
        cout << x << "-->" << z;
        newl;
        return;
    }
    tower(n - 1, x, z, y);
    cout << x << "-->" << z;
    newl;
    tower(n - 1, y, x, z);
}
vector<int> merge_Sort(vector<int> A)
{
    if (A.size() == 1)
    {
        return A;
    }
    vector<int> E, F;
    int m = A.size() / 2;
    for (int i = 0; i < m; i++)
    {
        E.P_B(A[i]);
    }
    for (int i = m; i < A.size(); i++)
    {
        F.P_B(A[i]);
    }
    vector<int> B = merge_Sort(E);
    vector<int> C = merge_Sort(F);
    vector<int> D;
    int x = 0, y = 0;
    while (x != B.size() || y != C.size())
    {
        if (B[x] < C[y] && x < B.size() && y < C.size())
        {
            D.push_back(B[x++]);
        }
        else if (B[x] == C[y] && x < B.size() && y < C.size())
        {
            D.push_back(B[x++]);
            D.push_back(C[y++]);
        }
        else if (B[x] > C[y] && x < B.size() && y < C.size())
        {
            D.push_back(C[y++]);
        }
        else if (B.size() < x)
        {
            D.push_back(C[y++]);
        }
        else if (C.size() < y)
        {
            D.push_back(B[x++]);
        }
    }
    return D;
}
class Birthday
{
    int day;
    int month;
    int year;

public:
    Birthday(int d = 0, int m = 0, int y = 0)
    {
        day = d;
        month = m;
        year = y;
        cout << "Birthday Constructor is called" << endl;
    }
    void setDate(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
    void Display()
    {
        cout << "Date: "<<day<<" / "<<month<<" / "<<year<<endl;
    }
    ~Birthday()
    {
        cout << "Birthday destructor is called" << endl;
    }
};
class Person
{
    string name;
    Birthday obj;

public:
    Person()
    {

    }
    Person(string s, int d = 0, int m = 0, int y = 0)
    {
        name = s;
        obj.setDate(d, m, y);
        cout << "Person Constructor is called" << endl;
    }
    void Display()
    {
        cout << "Name: " << name << endl;
        obj.Display();
    }
    ~Person()
    {
        cout << "Person destructor is called" << endl;
    }
};
int prec(char c)
{
    if(c=='^')
    {
        return 1;
    }
    else if(c=='*'||c=='/')
    {
        return 2;
    }
    else if(c=='+'||c=='-')
    {
        return 3;
    }
    return 10;
}
void merge_sort(int a,int low,int high)
{
    cout<<low<<" "<<high;newl;
    if(low<high)
    {
        int mid=(low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
    }
}
int main()
{
    // str r;
    // cin>>r;
    // r+=')';
    // int n=r.size();
    // stack<char>s;
    // s.push('(');
    // str res="";
    // for(int i=0;i<n;i++)
    // {
    //     if(r[i]>='A'&&r[i]<='Z')
    //     {
    //         res+=r[i];
    //     }
    //     else if(r[i]>='a'&&r[i]<='z')
    //     {
    //         res+=r[i];
    //     }
    //     else
    //     {
    //         if(r[i]=='('||prec(s.top())>prec(r[i]))
    //         {
    //             s.push(r[i]);
    //         }
    //         else if(r[i]==')')
    //         {
    //             while(s.top()!='(')
    //             {
    //                 res+=s.top();
    //                 s.pop();
    //             }
    //             s.pop();
    //         }
    //         else
    //         {
    //             res+=s.top();
    //             s.pop();
    //             s.push(r[i]);
    //         }
    //     }
    // }
    // cout<<res;
    // int *A[3];
    // A[0]=new int[5]{1,2,3,4,5};
    // A[0]++;
    // cout<<*A[0];
    queue<int>q;
    cout<<q.front();
}
 // a+(b+c)*d-e