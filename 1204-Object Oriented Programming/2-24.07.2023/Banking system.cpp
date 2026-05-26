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
class Bank
{
private:
    int id;
    float amount;
    static int n;
    static int total_balance;
public:
    Bank()
    {
        id=0;
        amount=0;
        n++;
    }
    Bank(int Id, float Amount)
    {
        id=Id;
        amount=Amount;
        total_balance+=Amount;
        n++;
    }
    // copy constructor
    Bank(int a,const Bank&other)
    {
        id=a;
        amount=other.amount;
        total_balance+=other.amount;
        n++;
    }
    void set_info(int i,float at)
    {
        id=i;
        amount=at;
        total_balance+=at;
    }
    void deposit(float Amount)
    {
        if(Amount>0)
        {
            amount+=Amount;
            total_balance+=Amount;
            cout<<"You have deposited "<<Amount;
            newl;
        }
        else
        {
            cout<<"Invalid amount";
            newl;
        }
    }
    void withdraw(float am)
    {
        if(amount>=am)
        {
            amount-=am;
            total_balance-=am;
            cout<<"You have withdrawn "<<am;
            newl;
        }
        else
        {
            cout<<"you don't have sufficient balance";
            newl;
        }
    }
    void Transfer(float am, Bank &other)
    {
        if(am<=amount)
        {
            amount-=am;
            other.amount+=am;
            cout<<"Id "<<id<<" has transfered "<<am<<" to Id "<<other.id<<" is successfull\n";
        }
        else
        {
            cout<<"invalid amount\n\n";
        }
    }
    void get_balance_and_client() const
    {
        cout<<"Your id is->";
        cout<<id;
        cout<<", Your account balance is "<<amount;
        cout<<", Total Client is->"<<n;
        newl;
    }
    void Bank_balance()
    {
        cout<<"Total balance of bank is ";
        cout<<total_balance;
        newl;
    }
};
int Bank::n=0;int Bank::total_balance=0;
int main()
{
    Bank p1;
    Bank p2(2,10000);
    p1.set_info(1,5000);
    Bank p3(3,p1);
    Bank p4(4,12000),p5(5,15000);
    p1.get_balance_and_client();
    p2.get_balance_and_client();
    p3.get_balance_and_client();
    p4.get_balance_and_client();
    p5.get_balance_and_client();
    p1.Bank_balance();
    p5.Transfer(3000,p1);
    p5.get_balance_and_client();
    p1.get_balance_and_client();
    p4.withdraw(1000);
    p4.get_balance_and_client();
    p4.Bank_balance();
    p1.deposit(1500);
    p1.get_balance_and_client();
    p1.Bank_balance();
}
