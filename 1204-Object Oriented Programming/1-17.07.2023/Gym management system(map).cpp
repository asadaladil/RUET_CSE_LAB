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
#include"shortenning.h"
using namespace std;
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
    cout<<"8. Exit\n";
    cout<<"Enter your option(1-8):_ "; 
}
struct member
{
    int member_id;
    float Height;
    float Weight;
};
int main()
{
    map<int,pair<float,float>>mp,mp1,mp2,mp3,mp4;
    start:
    menu();
    while(1)
    {
        int i;cin>>i;
        if(i==1)
        {
            begin:
            cout<<"Enter your member id: ";
            int a;cin>>a;
            if(mp.find(a)==mp.end())
            {
                cout<<"Enter your height: ";
                float x;cin>>x;
                cout<<"Enter your weight: ";
                float y;cin>>y;
                mp[a]={x,y};
                mp1[a]={x,y};
                mp2[a]={x,y};
                mp3[a]={x,y};
                mp4[a].first++;
                mp4[a].second++;
                cout<<"\nmember added successfully\n\nPress 8 to clear\n";
                flag:
                int b;cin>>b;
                if(b==8)
                {
                    clr;
                    goto start;
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
                cout<<"Member id is already registered\nPress 8 to clear\n";
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
        else if(i==2)
        {
            begin1:
            cout<<"Enter your member id: ";
            int a;cin>>a;
            if(mp.find(a)!=mp.end())
            {
                cout<<"Which you want to update\nPress 0 for height\nPress 1 for weight\nPress 2 for both\nyour option->";
                int m;cin>>m;
                if(m==0)
                {
                    cout<<"Present height->"<<mp[a].first;
                    newl;
                    cout<<"Enter your updated height: ";
                    float x;cin>>x;
                    mp[a]={x,mp[a].second};
                    mp1[a].first=max(mp1[a].first,x);
                    mp2[a].first=min(mp1[a].first,x);
                    mp3[a].first+=x;
                    mp4[a].first++;
                    cout<<"\nHeight updated successfully\n\nPress 8 to clear\n";
                }
                else if(m==1)
                {
                    cout<<"Present weight->"<<mp[a].second;
                    cout<<"\nEnter your updated weight: ";
                    float y;cin>>y;
                    mp[a]={mp[a].first,y};
                    mp1[a].second=max(mp1[a].second,y);
                    mp2[a].second=min(mp1[a].second,y);
                    mp3[a].second+=y;
                    mp4[a].second++;
                    cout<<"\nWeight updated successfully\n\nPress 8 to clear\n";
                }
                else if(m==2)
                {
                    cout<<"Present height->"<<mp[a].first;
                    newl;
                    cout<<"Enter your updated height: ";
                    float x;cin>>x;
                    mp[a]={x,mp[a].second};
                    mp1[a].first=max(mp1[a].first,x);
                    mp2[a].first=min(mp1[a].first,x);
                    mp3[a].first+=x;
                    mp4[a].first++;
                    cout<<"Present weight->"<<mp[a].second;
                    cout<<"\nEnter your updated weight: ";
                    float y;cin>>y;
                    mp[a]={mp[a].first,y};
                    mp1[a].second=max(mp1[a].second,y);
                    mp2[a].second=min(mp1[a].second,y);
                    mp3[a].second+=y;
                    mp4[a].second++;
                    cout<<"Height and Weight updated successfully\n\nPress 8 to clear\n";
                }
                flag1:
                int b;cin>>b;
                if(b==8)
                {
                    clr;
                    goto start;
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
                cout<<"member id is not found\nPress 8 to back\n";
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
        else if(i==3)
        {
            begin2:
            cout<<"Enter your member id: ";
            int a;cin>>a;
            if(mp.find(a)!=mp.end())
            {
                mp.erase(a);mp1.erase(a);mp2.erase(a);mp3.erase(a),mp4.erase(a); 
                cout<<"\nremoved successfully\n\nPress 8 to clear\n";
                flag2:
                int b;cin>>b;
                if(b==8)
                {
                    clr;
                    goto start;
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
                cout<<"member id is not found\nPress 8 to back\n";
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
        else if(i==4)
        {
            begin3:
            cout<<"Enter your member id: ";
            int a;cin>>a;
            if(mp.find(a)!=mp.end())
            {
                cout<<"Maximum height->"<<mp1[a].first<<endl;
                cout<<"Maximum weight->"<<mp1[a].second;
                newl;
                cout<<"\n\nPress 8 to clear\n";
                flag3:
                int b;cin>>b;
                if(b==8)
                {
                    clr;
                    goto start;
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
                cout<<"member id is not found\nPress 8 to back\n";
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
        else if(i==5)
        {
            begin4:
            cout<<"Enter your member id: ";
            int a;cin>>a;
            if(mp.find(a)!=mp.end())
            {
                cout<<"Minimum height->"<<mp2[a].first<<endl;
                cout<<"Minimum weight->"<<mp2[a].second;
                newl;
                cout<<"\n\nPress 8 to clear\n";
                flag4:
                int b;cin>>b;
                if(b==8)
                {
                    clr;
                    goto start;
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
                cout<<"member id is not found\nPress 8 to back\n";
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
        else if(i==6)
        {
            begin5:
            cout<<"Enter your member id: ";
            int a;cin>>a;
            if(mp.find(a)!=mp.end())
            {
                cout<<"Average height->"<<(mp3[a].first/mp4[a].first)<<endl;
                cout<<"Average weight->"<<(mp3[a].second/mp4[a].second);
                newl;
                cout<<"\n\nPress 8 to clear\n";
                flag5:
                int b;cin>>b;
                if(b==8)
                {
                    clr;
                    goto start;
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
                cout<<"member id is not found\nPress 8 to back\n";
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
        else if(i==7)
        {
            begin6:
            cout<<"Enter your member id: ";
            int a;cin>>a;
            if(mp.find(a)!=mp.end())
            {
                cout<<"Your BMI is->";
                float f=mp[a].second/(mp[a].first*mp[a].first);
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
                    goto start;
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
                cout<<"member id is not found\nPress 8 to back\n";
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
        else if(i==8)
        {
            clr;
            cout<<"Press 9 to restart the enquiry again-->";
            flag7:
            int b;cin>>b;
            if(b==9)
            {
                clr;
                goto start;
            }
            else
            {
                clr;
                cout<<"Enter correct keyword 9-->";
                goto flag7;
            }
        }
        else
        {
            clr;
            cout<<"Invalid keyword\n";
            cout<<"Press 9 to continue\n";
            flag8:
            int b;
            cin>>b;
            if(b==9)
            {
                clr;
                goto start;
            }
            else
            {
                clr;
                cout<<"Enter correct keyword 9-->";
                goto flag8;
            }
        }
    }

}
