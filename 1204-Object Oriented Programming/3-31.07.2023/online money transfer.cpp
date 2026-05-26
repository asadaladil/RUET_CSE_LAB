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
#include<conio.h> // for using getch function
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
int f(int x)
{
    if(x==1)
    {
        return 1;
    }
    return x*f(x-1);
}
#define __lcm(x,y) (x*y)/__gcd(x,y)
#define A_sort(x) sort(x.begin(),x.end())
#define D_sort(x) sort(x.rbegin(),x.rend())
#define reverse(x) reverse(x.begin(),x.end())
#define yes_or_no cout<<"YES\n":cout<<"NO\n"
#define yess cout<<"YES\n"
#define noo cout<<"NO\n"
#define endl "\n"
#define newl cout<<endl
#define clr system("cls");
int main();
class myCash;
vector<myCash>members(1000);
map<str,int>mp,mp2;
int on=0;
int id(str m)
{
    return mp[m];
}
void menu()
{
    cout<<"*********MyCash menu**********\n";
    cout<<"1. Update Me\n2. Remove Me\n3. Send Money\n4. Cash-in\n5. Cash-out\n6. Pay Bill\n7. Check Balance\n8. History\n9. Logout\n";
    cout<<"Enter Your Option (1-9):_";
    newl;
}
bool m_check(str s)
{
    int n=s.size();
    for(int i=0; i<n; i++)
    {
        if(s[i]>='0'&&s[i]<='9'&&s[0]=='0'&&s[1]=='1')
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
void login()
{
    cout<<"*********MyCash Login**********\n";
    cout<<"1. Login\n2. Register\n3. Exit\nEnter Your Option: ";
}
int OTP_gen()
{
    int x;
    srand(time(0));
    x=1000+rand()%9000;
    return x;
}
str pass_gen()
{
    str p="";
    char ch;
    ch=getch();
    while(ch!=13)
    {
        p.P_B(ch);
        cout<<"*";
        ch=getch();
    }
    newl;
    return p;
}
int total=1;
int member=0;
class myCash
{
public:
    str name,mobile,pin;
    double balance;
    vector<pair<str,double>>his;
    myCash()
    {

    }
    void set_info(str m,str p,str n,double b)
    {
        mobile=m;
        pin=p;
        name=n;
        balance=b;
    }
    void set_history(vector<pair<str,double>>M)
    {
        his=M;
    }
    void login(str n, str p)
    {
        if(n==mobile&&p==pin)
        {
jao5:
            clr
            menu();
            int a;
            cin>>a;
            if(a==1)
            {
                update();
            }
            else if(a==2)
            {
                remove();
            }
            else if(a==3)
            {
                send();
            }
            else if(a==4)
            {
                cash_in();
            }
            else if(a==5)
            {
                cash_out();
            }
            else if(a==6)
            {
                pay_bill();
            }
            else if(a==7)
            {
                c_balance();
            }
            else if(a==8)
            {
                History();
            }
            else if(a==9)
            {
                logout();
            }
            else
            {
                cout<<"Invalid option\n";
                cout<<"\n Press any key to continue\n";
                getchar();
                getchar();
                clr
                goto jao5;
            }
        }
        else
        {
            cout<<"password or mobile number is incorrect\nPress any key to continue ";
            getchar();
            getchar();
            clr;
            main();
        }
    }
private:
    void update()
    {
jao2:
        cout<<"Enter your option\n";
        cout<<"1. Update name\n2. Update Pin\n";
        cout<<"Your option-> ";
        int a;
        cin>>a;
        getchar();
        if(a==1)
        {
            cout<<"Old name->"<<name;
            newl;
            cout<<"New name->";
            getline(cin,name);
            cout<<"Name Upadted Succesfully\n";
            cout<<"Press enter to continue";
            getchar();
            login(mobile,pin);
        }
        else if(a==2)
        {
            cout<<"Old pin->"<<pin;
            newl;
            cout<<"New Pin->";
            str s=pass_gen();
            if(s.length()==5)
            {
                pin=s;
                cout<<"pin updated succcesfully\n";
                cout<<"Press enter to continue";
                getchar();
                clr
                login(mobile,pin);
            }
            else
            {
                cout<<"size must be 5";
                cout<<"press enter to continue\n";
                getchar();
                getchar();
                clr;
                goto jao2;
            }
        }
        else
        {
            cout<<"you have entered incorrect key\n";
            cout<<"press enter to continue";
            getchar();
            getchar();
            clr
            goto jao2;
        }
    }
    void remove()
    {
jao6:
        clr
        cout<<"\nARE YOU SURELY WANT TO DELETE YOUR ACCOUNT\n";
        cout<<"Press Y for YES or N for NO: ";
        char c;
        cin>>c;
        if(c=='Y'||c=='y')
        {
            mp.erase(mobile);
            cout<<"Successfully Removed Account\n";
            cout<<"Press any key to continue\n";
            member--;
            getchar();
            getchar();
            clr;
            main();
        }
        else if(c=='N'||c=='n')
        {
            clr
            login(mobile,pin);
        }
        else
        {
            cout<<"Invalid Keyword\nPress any key to continue ";
            getchar();
            getchar();
            goto jao6;
        }
    }
    void send()
    {
        cout<<"Enter mobille number: ";
        str n;
        cin>>n;
        if(mp[n])
        {
            cout<<"Enter Amount: ";
            int l;
            cin>>l;
            cout<<"Enter your pin: ";
            str r=pass_gen();
            if(pin==r)
            {
                members[mp[n]].balance+=l;
                balance-=l;
                cout<<"Send money to "<<n<<" is successful\nPress enter to continue\n";
                his.P_B({n+"_has_received_money_of",l});
                members[mp[n]].his.P_B({mobile+"_has_sent_money_to_your_account",l});
                getchar();
                getchar();
                clr
                login(mobile,pin);
            }
            else
            {
                cout<<"pin is incorrect\nPress enter to continue\n";
                getchar();
                getchar();
                clr
                login(mobile,pin);
            }
        }
        else
        {
            cout<<"Mobile number not found\n";
            cout<<"Press any key to continue ";
            getchar();
            getchar();
            clr
            login(mobile,pin);
        }
    }
    void cash_in()
    {
        cout<<"Enter amount ";
        int l;
        cin>>l;
        this->balance+=l;
        his.P_B({"You_have_cash_in_the_money",l});
        cout<<"Cash-in Succesfull\n";
        cout<<"Press any key to continue ";
        getchar();
        getchar();
        clr
        login(mobile,pin);
    }
    void cash_out()
    {
        cout<<"Enter amount: ";
        int l;
        cin>>l;
        if(l>balance)
        {
            cout<<"Not enough amount\n";
            cout<<"Press any key to continue: ";
            getchar();
            getchar();
            clr
            login(mobile,pin);
        }
        this->balance-=l;
        his.P_B({"You_have_cash_out_the_money",l});
        cout<<"Cash-out Succesfull\n";
        cout<<"Press any key to continue ";
        getchar();
        getchar();
        clr;
        login(mobile,pin);
    }
    void pay_bill()
    {
        cout<<"Enter pay bill id: ";
        str r;
        cin>>r;
        cout<<"Enter amount: ";
        int l;
        cin>>l;
        if(l>balance)
        {
            cout<<"Not enough amount\n";
            cout<<"Press any key to continue: ";
            getchar();
            getchar();
            clr
            login(mobile,pin);
        }
        this->balance-=l;
        his.P_B({"You_have_pay_bill_the_money",l});
        cout<<"Bill Pay to id "<<r<<" is Succesfull\n";
        cout<<"Press any key to continue ";
        getchar();
        getchar();
        clr;
        login(mobile,pin);
    }
    void c_balance()
    {
        cout<<"Your Account Balance is "<<balance;
        newl;
        cout<<"Press any key to continue ";
        getchar();
        getchar();
        clr
        login(mobile,pin);
    }
    void History()
    {
        if(his.size()==0)
        {
            cout<<"There is no History to show right now";
            newl;
            cout<<"Press any key to continue ";
            getchar();
            getchar();
            clr
            login(mobile,pin);
        }
        int i=1;
        newl;
        for(auto it:his)
        {
            cout<<i<<". ";
            cout<<it.first<<" "<<it.second;
            newl;
            i++;
        }
        cout<<"Press any key to continue ";
        getchar();
        getchar();
        clr
        login(mobile,pin);
    }
    void logout()
    {
        cout<<"You have succesfully loged out\nPress any key to continue ";
        getchar();
        getchar();
        clr;
        main();
    }
};
int main()
{
    if(on==0)
    {
        ifstream inputfile,hist;
        inputfile.open("data.txt");
        hist.open("History.txt");
        if(inputfile.is_open())
        {
            int i=1;
            str x,y,z;
            double b;
            while(inputfile>> x >> y >> z >>b)
            {
                members[i].set_info(x,y,z,b);
                mp[x]=i;
                i++;
            }
            total=i;
            member=i-1;
        }
        if(hist.is_open())
        {
            int x;
            hist>>x;
            int y=1;
            while(x!=-1)
            {
                str s; double b;
                vector<pair<str,double>>A;
                for(int i=0;i<x;i++)
                {
                    hist>>s>>b;
                    A.P_B({s,b});
                }
                members[y].set_history(A);
                hist>>x;
                y++;
            }
        }
        on=1;
    }
start:
    login();
    while(1)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            clr
            cout<<"Enter your phone number: ";
            str n;
            cin>>n;
            if(mp[n])
            {
                cout<<"Enter your pin: ";
                str p=pass_gen();
                members[mp[n]].login(n,p);
            }
            else
            {
                cout<<"Phone Number not registered\n";
                cout<<"Press any key to continue\n";
                getchar();
                getchar();
                clr
                goto start;
            }
        }
        else if(x==2)
        {
jaoo:
            clr
            str mobile;
            cout<<"Enter your mobile number: \n";
            cin>>mobile;
            if(mobile.size()!=11&&m_check(mobile))
            {
                cout<<"Mobile number is incorrect\npress enter to continue";
                getchar();
                getchar();
                goto jaoo;
            }
            else if(mp[mobile])
            {
                cout<<"mobile number is already registered\npress enter to continue";
                getchar();
                getchar();
                clr;
                main();
            }
            else
            {
                str name;
                cout<<"Enter your name: ";
                cin>>name;
                cout<<"Enter pin (5-digits): ";
                str r=pass_gen();
                if(r.size()!=5)
                {
                    cout<<"Pin must be 5 digit\nPress enter to continue;";
                    getchar();
                    getchar();
                    clr;
                    main();
                }
                cout<<"Reconfirm pin: ";
                str pin=pass_gen();
                if(pin==r&&r.size()==5)
                {
                    int a=OTP_gen();
                    cout<<"YOUR MYCASH OTP---> "<<a;
                    newl;
                    cout<<"Enter your OTP which is send to "<<mobile;
                    newl;
                    int b;
                    cin>>b;
                    if(b==a)
                    {
                        cout<<"Enter amount of first deposit: ";
                        double balance;
                        cin>>balance;
                        cout<<"Registration succesfull\n";
                        cout<<"Press any key to continue\n";
                        mp[mobile]=total;
                        members[mp[mobile]].set_info(mobile,pin,name,balance);
                        total++;
                        member++;
                        mp2[mobile]=0;
                        getchar();
                        getchar();
                        clr
                        main();
                    }
                    else
                    {
                        cout<<"registartion failed\n";
                        cout<<"press enter to continue ";
                        getchar();
                        getchar();
                        clr
                        main();
                    }
                }
            }
        }
        else if(x==3)
        {
            ofstream outputfile("data.txt"),ho("History.txt");
            for(auto it:mp)
            {
                int i=it.second;
                outputfile<<members[i].mobile<<" "<<members[i].pin<<" "<<members[i].name<<" "<<members[i].balance<<endl;
            }
            for(auto iit:mp)
            {
                ho<<members[iit.second].his.size()<<endl;
                for(auto it:members[iit.second].his)
                {
                    ho<<it.first<<" "<<it.second<<endl;
                }
            }
            ho<<-1;
            return 0;
        }
        else
        {
            cout<<"Invalid Key\nPress any key to continue";
            getchar();
            getchar();
            main();
        }
    }
}
