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
int f(int x)
{
    if (x == 1)
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

template<typename t1,typename t2>
class A
{
private:
    t1 x;
    t2 y;

public:
    void setData(t1 x, t2 y)
    {
        this->x = x;
        this->y = y;
    }
    auto Sum()
    {
        auto s=x+y;
        return s;
    }
};
int main()
{
    // write required statements to call SetData() & Sum()
    A<int,int>a1;
    a1.setData(5,3);
    cout<<a1.Sum();
    newl;
    A<int,double>a2;
    a2.setData(5,3.25);
    cout<<a2.Sum();
    newl;
    A<double,int>a3;
    a3.setData(6.55,4);
    cout<<a3.Sum();
    newl;
    A<double,double>a4;
    a4.setData(6.25,5.66);
    cout<<a4.Sum();
    newl;

}
