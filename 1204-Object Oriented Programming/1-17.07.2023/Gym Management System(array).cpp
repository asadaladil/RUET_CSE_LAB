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
#define clr system("cls")
using namespace std;
const int N=1e4;
int main();
void classify(float x)
{
    if(x>40)
    {
        cout<<"Obese Class III";
    }
    else if(x>=35)
    {
        cout<<"Obese Class II";
    }
    else if(x>=30)
    {
        cout<<"Obese Class I";
    }
    else if(x>=25)
    {
        cout<<"Overweight";
    }
    else if(x>=18.5)
    {
        cout<<"Normal";
    }
    else if(x>=17)
    {
        cout<<"Mlid Thinness";
    }
    else if(x>=16)
    {
        cout<<"Moderate Thinness";
    }
    else
    {
        cout<<"Severe Thinness";
    }
}
void menu()
{
    cout<<"********** Main Menu **********\n";
    cout<<"1. Add member\n2. Update member\n3. Remove member\n";
    cout<<"4. Max height & weight\n5. Min height & weight\n";
    cout<<"6. Average height & weight\n7. BMI classification\n";
    cout<<"8. Show member's Height and weight\n";
    cout<<"9. Found Member\n10. Exit\n";
    cout<<"Enter your option(1-10):_ "; 
}
bool check_height(float x)
{
    if(x<0.30||x>2.5)
    {
        cout<<"Height should be between 0.3 to 2.5 meter\n";
        cout<<"\nPress 1 to back\n";
        abar:
        int b;cin>>b;
        if(b==1)
        {
            newl;
            return true;
        }
        else
        {
            clr;
            cout<<"Press correct keyword 1\n";
            goto abar;
        }
    }
    return false;
}
bool check_weight(float x)
{
    if(x<3||x>500)
    {
        cout<<"weight should be between 3 to 500 KG\n";
        cout<<"\nPress 1 to back\n";
        abar1:
        int b;cin>>b;
        if(b==1)
        {
            newl;
            return true;
        }
        else
        {
            clr;
            cout<<"Press correct keyword 1\n";
            goto abar1;
        }
    }
    return false;
}
struct member
{
    int member_id;
    float Height;
    float Weight;
};
struct member Gym[N],Gym1[N],Gym2[N],Gym3[N],Gym4[N];
/*memset(Gym,0,sizeof(Gym));
memset(Gym1,0,sizeof(Gym1));
memset(Gym2,0,sizeof(Gym2));
memset(Gym3,0,sizeof(Gym3));
memset(Gym4,0,sizeof(Gym4));*/
void Add()
{
    begin:
    cout<<"Enter your member id: ";
    int a;cin>>a;
    if(Gym[int(a)].member_id==0)
    {
        hoyni:
        cout<<"Enter your height (Meter): ";
        float x;cin>>x;
        if(check_height(x))
        {
            clr;
            menu();
            goto hoyni;
        }
        hoyni1:
        cout<<"Enter your weight (KG): ";
        float y;cin>>y;
        if(check_weight(y))
        {
            clr;
            menu();
            goto hoyni1;
        }
        Gym[a].member_id=a;
        Gym[a].Height=x;
        Gym[a].Weight=y;
        Gym1[a].member_id=a;
        Gym1[a].Height=x;
        Gym1[a].Weight=y;
        Gym2[a].member_id=a;
        Gym2[a].Height=x;
        Gym2[a].Weight=y;
        Gym3[a].member_id=a;
        Gym3[a].Height=x;
        Gym3[a].Weight=y;
        Gym4[a].member_id=a;
        Gym4[a].Height++;
        Gym4[a].Weight++;
        cout<<"\nmember added successfully\n\nPress 8 to clear\n";
        flag:
        int b;cin>>b;
        if(b==8)
        {
            clr;
            main();
        }
        else
        {
            clr;
            menu();
            newl;
            cout<<"Enter correct keyword 8\n";
            goto flag;
        }
    }
    else
    {
        cout<<"Member id is already registered or Invalid Key word\nPress 8 to clear\n";
        again:
        int b;cin>>b;
        if(b==8)
        {
            clr;
            menu();
            newl;
            goto begin;
        }
        else
        {
            clr;
            menu();
            newl;
            cout<<"Enter correct keyword 8\n";
            goto again;
        }
    }
}
void update()
{
    begin1:
    cout<<"Enter your member id: ";
    int a;cin>>a;
    if(Gym[int(a)].member_id!=0)
    {
        cout<<"Which you want to update\nPress 0 for height\nPress 1 for weight\nPress 2 for both\nyour option->";
        int m;cin>>m;
        if(m==0)
        {
            hoyni2:
            cout<<"Present height->"<<Gym[a].Height;
            newl;
            cout<<"Enter your updated height (Meter): ";
            float x;cin>>x;
            if(check_height(x))
            {
                clr;
                menu();
                goto hoyni2;
            }
            Gym[a].Height=x;
            Gym1[a].Height=max(Gym1[a].Height,x);
            Gym2[a].Height=min(Gym2[a].Height,x);
            Gym3[a].Height+=x;
            Gym4[a].Height++;
            cout<<"\nHeight updated successfully\n\nPress 8 to clear\n";
        }
        else if(m==1)
        {
            hoyni3:
            cout<<"Present weight->"<<Gym[a].Weight;
            cout<<"\nEnter your updated weight (KG): ";
            float y;cin>>y;
            if(check_weight(y))
            {
                clr;
                menu();
                goto hoyni3;
            }
            Gym[a].Weight=y;
            Gym1[a].Weight=max(Gym1[a].Weight,y);
            Gym2[a].Weight=min(Gym2[a].Weight,y);
            Gym3[a].Weight+=y;
            Gym4[a].Weight++;
            cout<<"\nWeight updated successfully\n\nPress 8 to clear\n";
        }
        else if(m==2)
        {
            hoyni4:
            cout<<"Present height->"<<Gym[a].Height;
            newl;
            cout<<"Enter your updated height (Meter): ";
            float x;cin>>x;
            if(check_height(x))
            {
                clr;
                menu();
                goto hoyni4;
            }
            Gym[a].Height=x;
            Gym1[a].Height=max(Gym1[a].Height,x);
            Gym2[a].Height=min(Gym2[a].Height,x);
            Gym3[a].Height+=x;
            Gym4[a].Height++;
            hoyni5:
            cout<<"Present weight->"<<Gym[a].Weight;
            cout<<"\nEnter your updated weight (KG): ";
            float y;cin>>y;
            if(check_weight(y))
            {
                clr;
                menu();
                goto hoyni5;
            }
            Gym[a].Weight=y;
            Gym1[a].Weight=max(Gym1[a].Weight,y);
            Gym2[a].Weight=min(Gym2[a].Weight,y);
            Gym3[a].Weight+=y;
            Gym4[a].Weight++;
            cout<<"Height and Weight updated successfully\n\nPress 8 to clear\n";
        }
        flag1:
        int b;cin>>b;
        if(b==8)
        {
            clr;
            main();
        }
        else
        {
            clr;
            menu();
            newl;
            cout<<"Enter correct keyword 8\n";
            goto flag1;
        }
    }
    else
    {
        cout<<"member id is not found or Invalid Key word\nPress 8 to back\n";
        again1:
        int b;cin>>b;
        if(b==8)
        {
            clr;
            menu();
            newl;
            goto begin1;
        }
        else
        {
            clr;
            menu();
            newl;
            cout<<"Enter correct keyword 8\n";
            goto again1;
        }
    }
}
void remove()
{
    begin2:
    cout<<"Enter your member id: ";
    int a;cin>>a;
    if(Gym[int(a)].member_id!=0)
    {
        Gym[a]={0,0,0};Gym1[a]={0,0,0};Gym2[a]={0,0,0};Gym3[a]={0,0,0};Gym4[a]={0,0,0}; 
        cout<<"\nremoved successfully\n\nPress 8 to clear\n";
        flag2:
        int b;cin>>b;
        if(b==8)
        {
            clr;
            main();
        }
        else
        {
            clr;
            menu();
            newl;
            cout<<"Enter correct keyword 8\n";
            goto flag2;
        }
    }
    else
    {
        cout<<"member id is not found or Invalid Key word\nPress 8 to back\n";
        again2:
        int b;cin>>b;
        if(b==8)
        {
            clr;
            menu();
            newl;
            goto begin2;
        }
        else
        {
            clr;
            menu();
            newl;
            cout<<"Enter correct keyword 8\n";
            goto again2;
        }
    }
}
void Mh_Mw()
{
    begin3:
    cout<<"Enter your member id: ";
    int a;cin>>a;
    if(Gym[int(a)].member_id!=0)
    {
        cout<<"Maximum height->"<<Gym1[a].Height<<endl;
        cout<<"Maximum weight->"<<Gym1[a].Weight;
        newl;
        cout<<"\n\nPress 8 to clear\n";
        flag3:
        int b;cin>>b;
        if(b==8)
        {
            clr;
            main();
        }
        else
        {
            clr;
            menu();
            newl;
            cout<<"Enter correct keyword 8\n";
            goto flag3;
        }
    }
    else
    {
        cout<<"member id is not found or Invalid Key word\nPress 8 to back\n";
        again3:
        int b;cin>>b;
        if(b==8)
        {
            clr;
            menu();
            newl;
            goto begin3;
        }
        else
        {
            clr;
            menu();
            newl;
            cout<<"Enter correct keyword 8\n";
            goto again3;
        }
    }
}
void mh_mw()
{
    begin4:
    cout<<"Enter your member id: ";
    int a;cin>>a;
    if(Gym[int(a)].member_id!=0)
    {
        cout<<"Minimum height->"<<Gym2[a].Height<<endl;
        cout<<"Minimum weight->"<<Gym2[a].Weight;
        newl;
        cout<<"\n\nPress 8 to clear\n";
        flag4:
        int b;cin>>b;
        if(b==8)
        {
            clr;
            main();
        }
        else
        {
            clr;
            menu();
            newl;
            cout<<"Enter correct keyword 8\n";
            goto flag4;
        }
    }
    else
    {
        cout<<"member id is not found or Invalid Key word\nPress 8 to back\n";
        again4:
        int b;cin>>b;
        if(b==8)
        {
            clr;
            menu();
            newl;
            goto begin4;
        }
        else
        {
            clr;
            menu();
            newl;
            cout<<"Enter correct keyword 8\n";
            goto again4;
        }
    }
}
void Ah_Aw()
{
    begin5: 
    cout<<"Enter your member id: ";
    int a;cin>>a;
    if(Gym[int(a)].member_id!=0)
    {
        cout<<"Average height->"<<(Gym3[a].Height/Gym4[a].Height)<<endl;
        cout<<"Average weight->"<<(Gym3[a].Weight/Gym4[a].Weight);
        newl;
        cout<<"\n\nPress 8 to clear\n";
        flag5:
        int b;cin>>b;
        if(b==8)
        {
            clr;
            main();
        }
        else
        {
            clr;
            menu();
            newl;
            cout<<"Enter correct keyword 8\n";
            goto flag5;
        }
    }
    else
    {
        cout<<"member id is not found or Invalid Key word\nPress 8 to back\n";
        again5:
        int b;cin>>b;
        if(b==8)
        {
            clr;
            menu();
            newl;
            goto begin5;
        }
        else
        {
            clr;
            menu();
            newl;
            cout<<"Enter correct keyword 8\n";
            goto again5;
        }
    }
}
void BMI()
{
    begin6:
    cout<<"Enter your member id: ";
    int a;cin>>a;
    if(Gym[a].member_id!=0)
    {
        cout<<"Your BMI is->";
        float f=Gym[a].Weight/(Gym[a].Height*Gym[a].Height);
        cout<<f;
        newl;
        cout<<"Your BMI classification--->";
        classify(f);
        cout<<"\n\nPress 8 to clear\n";
        flag6:
        int b;cin>>b;
        if(b==8)
        {
            clr;
            main();
        }
        else
        {
            clr;
            menu();
            newl;
            cout<<"Enter correct keyword 8\n";
            goto flag6;
        }
    }
    else
    {
        cout<<"member id is not found or Invalid Key word\nPress 8 to back\n";
        again6:
        int b;cin>>b;
        if(b==8)
        {
            clr;
            menu();
            newl;
            goto begin6;
        }
        else
        {
            clr;
            menu();
            newl;
            cout<<"Enter correct keyword 8\n";
            goto again6;
        }
    }
}
void show()
{
    begin8:
    cout<<"Enter your member id: ";
    int a;cin>>a;
    if(Gym[a].member_id!=0)
    {
        cout<<"\nYour member id->"<<a;
        cout<<"\nYour Height is->"<<Gym[a].Height;
        cout<<"\nYour Weight is->"<<Gym[a].Weight;
        cout<<"\n\nPress 8 to clear\n";
        flag8:
        int b;cin>>b;
        if(b==8)
        {
            clr;
            main();
        }
        else
        {
            clr;
            menu();
            newl;
            cout<<"Enter correct keyword 8\n";
            goto flag8;
        }
    }
    else
    {
        cout<<"member id is not found or Invalid Key word\nPress 8 to back\n";
        again8:
        int b;cin>>b;
        if(b==8)
        {
            clr;
            menu();
            newl;
            goto begin8;
        }
        else
        {
            clr;
            menu();
            newl;
            cout<<"Enter correct keyword 8\n";
            goto again8;
        }
    }
}
void exit()
{
    clr;
    cout<<"Press 1 to restart the enquiry again-->";
    flag7:
    int b;cin>>b;
    if(b==1)
    {
        clr;
        main();
    }
    else
    {
        clr;
        cout<<"Enter correct keyword 9-->";
        goto flag7;
    }
}
void found()
{
    begin8:
    cout<<"Enter your member id: ";
    int a;cin>>a;
    if(Gym[a].member_id!=0)
    {
        cout<<"\nMember Found\n";
        cout<<"\n\nPress 8 to clear\n";
        flag8:
        int b;cin>>b;
        if(b==8)
        {
            clr;
            main();
        }
        else
        {
            clr;
            menu();
            newl;
            cout<<"Enter correct keyword 8\n";
            goto flag8;
        }
    }
    else
    {
        cout<<"member is Not Found\nPress 8 to back\n";
        again8:
        int b;cin>>b;
        if(b==8)
        {
            clr;
            menu();
            newl;
            goto begin8;
        }
        else
        {
            clr;
            menu();
            newl;
            cout<<"Enter correct keyword 8\n";
            goto again8;
        }
    }
}
void rej()
{
    clr;
    cout<<"Invalid keyword\n";
    cout<<"Press 9 to continue\n";
    flag9:
    int b;
    cin>>b;
    if(b==9)
    {
        clr;
        main();
    }
    else
    {
        clr;
        cout<<"Enter correct keyword 9-->";
        goto flag9;
    }
}
int main()
{
    menu();
    while(1)
    {
        int i;cin>>i;
        if(i==1)
        {
            Add();
        }
        else if(i==2)
        {
            update();
        }
        else if(i==3)
        {
            remove();
        }
        else if(i==4)
        {
            Mh_Mw();
        }
        else if(i==5)
        {
            mh_mw();
        }
        else if(i==6)
        {
            Ah_Aw();
        }
        else if(i==7)
        {
            BMI();
        }
        else if(i==8)
        {
            show();
        }
        else if(i==9)
        {
            found();
        }
        else if(i==10)
        {
            exit();
        }
        else
        {
            rej();
        }
    }
}
