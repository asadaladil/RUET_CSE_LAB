#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define str string
#define newl cout<<endl

map<str,double>mp;
set<char>st={'x','y','+','-','*','=','^','.'};
bool flag=false;
int eq=-1;
double digit(str r,int i)
{
    double a=0;int yy=0;
    bool fl=true;
    for(int k=i-1;k>=0;k--)
    {
        if(fl && r[k]>='0' && r[k]<='9' && (r[k+1]=='+'||r[k+1]=='-'||r[k+1]=='='))
        {
            a+=(r[k]-'0')*pow(10,yy);
            yy++;
            fl=false;
        }
        else if(yy==0&&a>0&&a<1)
        {
            a+=(r[k]-'0')*pow(10,yy);
            yy++;
        }
        else if(yy>0 && fl==false)
        {
            if(r[k]=='.')
            {
                a/=pow(10,yy);
                yy=0;
            }
            if(r[k]>='0' && r[k]<='9')
            {
                a+=(r[k]-'0')*pow(10,yy);
                yy++;
            }
            else if(r[k]=='-'||r[k]=='+')
            {
                if(r[k]=='-')
                {
                    a*=-1;
                    return a;
                }
                if(r[k]=='+')
                {
                    return a;
                }
            }
        }
    }
    return a;
}
void determine(str s)
{
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='x' && (s[i+1]=='+'||s[i+1]=='-'||s[i+1]=='='))
        {
            double xx=0;int yy=0;
            for(int k=i-1;;k--)
            {
                if(k>=0&&s[k]>='0'&&s[k]<='9')
                {
                    xx+=(s[k]-'0')*pow(10,yy);s[k]='p';
                    yy++;
                }
                else
                {
                    if(s[k]=='.')
                    {
                        xx/=pow(10,yy);
                        yy=0;
                        continue;
                    }
                    if(xx==0&&yy==0&&s[k]!='*'&&s[k]!='y')
                    {
                        xx=1;
                    }
                    if((i<eq&&s[k]=='-')||(i>eq&&(s[k]=='+'||s[k]=='=')))
                    {
                        xx*=-1;
                    }
                    mp["x"]+=xx/2;
                    break;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='y' &&(s[i+1]=='+'||s[i+1]=='-'||s[i+1]=='='))
        {
            double xx=0;int yy=0;
            for(int k=i-1;;k--)
            {
                if(k>=0&&s[k]>='0'&&s[k]<='9')
                {
                    xx+=(s[k]-'0')*pow(10,yy);s[k]='p';
                    yy++;
                }
                else
                {
                    if(s[k]=='.')
                    {
                        xx/=pow(10,yy);
                        yy=0;
                        continue;
                    }
                    if(xx==0&&yy==0&&s[k]!='*'&&s[k]!='x')
                    {
                        xx=1;
                    }
                    if((i<eq&&s[k]=='-')||i>eq && (s[k]=='+'||s[k]=='='))
                    {
                        xx*=-1;
                    }
                    mp["y"]+=xx/2;
                    break;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if((s[i]=='x' && s[i+1]=='y' || s[i]=='y' && s[i+1]=='x'))
        {
            double xx=0;int yy=0;
            for(int k=i-1;;k--)
            {
                if(k>=0&&s[k]>='0'&&s[k]<='9')
                {
                    xx+=(s[k]-'0')*pow(10,yy);s[k]='p';
                    yy++;
                }
                else
                {
                    if(s[k]=='.')
                    {
                        xx/=pow(10,yy);
                        yy=0;
                        continue;
                    }
                    if(xx==0&&yy==0)
                    {
                        xx=1;
                    }
                    if((i<eq&&s[k]=='-')||i>eq&&(s[k]=='+'||s[k]=='='))
                    {
                        xx*=-1;
                    }
                    mp["xy"]+=xx/2;
                    break;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='x'&&s[i+1]=='*'&&s[i+2]=='x')
        {
            double xx=0;int yy=0;
            for(int k=i-1;;k--)
            {
                if(k>=0&&s[k]>='0'&&s[k]<='9')
                {
                    xx+=(s[k]-'0')*pow(10,yy);s[k]='p';
                    yy++;
                }
                else
                {
                    if(s[k]=='.')
                    {
                        xx/=pow(10,yy);
                        yy=0;
                        continue;
                    }
                    if(xx==0&&yy==0)
                    {
                        xx=1;
                    }
                    if((i<eq&&s[k]=='-')||i>eq&&(s[k]=='+'||s[k]=='='))
                    {
                        xx*=-1;
                    }
                    mp["x*x"]+=xx;
                    break;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='y'&&s[i+1]=='*'&&s[i+2]=='y')
        {
            double xx=0;int yy=0;
            for(int k=i-1;;k--)
            {
                if(k>=0&&s[k]>='0'&&s[k]<='9')
                {
                    xx+=(s[k]-'0')*pow(10,yy);s[k]='p';
                    yy++;
                }
                else
                {
                    if(s[k]=='.')
                    {
                        xx/=pow(10,yy);
                        yy=0;
                        continue;
                    }
                    if(xx==0&&yy==0)
                    {
                        xx=1;
                    }
                    if((i<eq&&s[k]=='-')||i>eq&&(s[k]=='+'||s[k]=='='))
                    {
                        xx*=-1;
                    }
                    mp["y*y"]+=xx;
                    break;
                }
            }
        }
    }
    double xx=0;int yy=0,z;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            xx+=(s[i]-'0')*pow(10,yy);
            yy++;
        }
        else
        {
            if(s[i]=='.')
            {
                xx/=pow(10,yy);
                yy=0;
            }
            else if(s[i]=='-')
            {
                z=i;
                break;
            }
            else if(s[i]=='='||s[i]=='+')
            {
                xx*=-1;
                z=i;
                break;
            }
        }
    }
    xx+=digit(s,z);
    mp["cons"]+=xx;
}
void transfer(str &r)
{
    int n=r.size();
    for(int i=0;i<n;i++)
    {
        if(st.find(r[i])==st.end())
        {
            if(r[i]>='0'&&r[i]<='9'){goto jamp;}
            else{flag=true;}
        }
        jamp:
        if(r[i]=='=')
        {
            eq=i;
        }
        if(r[i]=='^'&&r[i+1]!='2')
        {
            flag=true;
        }
        if(r[i]=='^'&&r[i+1]=='2')
        {
            r[i]='*';
            r[i+1]=r[i-1];
        }
    }
}
int main()
{
    cout<<"Give Expression-> ax^2 + by^2 + 2hxy + 2gx + 2fy + c = 0";newl;newl;
    str r;
    cin>>r;
    transfer(r);
    str c1="xy",c2="x",c3="y",c4="x*x",c5="y*y",c6="cons";
    determine(r);
    if(flag||eq==-1)
    {
        cout<<"Invalid Equation";
        return 0;
    }
    cout<<"Co-efficient of x^2--> "<<mp[c4];
    newl;newl;
    cout<<"Co-efficient of y^2--> "<<mp[c5];
    newl;newl;
    cout<<"Co-efficient of xy--> "<<mp[c1]*2;
    newl;newl;
    cout<<"Co-efficient of x--> "<<mp[c2]*2;
    newl;newl;
    cout<<"Co-efficient of y--> "<<mp[c3]*2;
    newl;newl;
    cout<<"Value of constant--> "<<mp[c6];
    newl;newl;
    double a=mp[c4],b=mp[c5],c=mp["cons"],g=mp["x"],f=mp["y"],h=mp["xy"];

    double d=h*h-a*b,k=g*g+f*f-c;
    double D=a*(b*c-f*f)-h*(h*c-g*f)+g*(h*f-b*g);
    newl;newl;
    if(a==0&&b==0&&h==0&&g==0&&f==0)
    {
        cout<<"Inavalid Equation";
    }
    else if(a==b&&h==0&&k>=0&&a!=0&&b!=0)
    {
        cout<<"Your Curve is---> ";
        cout<<"Circle";
    }
    else if(a==0&&b==0&&h==0&&(g!=0||f!=0))
    {
        cout<<"Your Curve is---> ";
        cout<<"Straight Line";
    }
    else if(d==0 && (a!=0||b!=0))
    {
        cout<<"Your Curve is---> ";
        cout<<"Parabola";
    }
    else if(d<0&& a!=0 &&b!=0)
    {
        cout<<"Your Curve is---> ";
        cout<<"Ellipse";
    }
    else if(d>0 &&a!=0&&b!=0)
    {
        cout<<"Your Curve is---> ";
        cout<<"Hyperbola";
    }
    else if(D==0)
    {
        cout<<"Your Curve is---> ";
        cout<<"Pair of Straight Line";
    }
    newl;newl;
    mp.clear();
    flag=false;eq=-1;
    main();
}


/*
Circle:
x^2+y^2+0xy-8x-10y+1=0
x^2+y^2+0xy-2x-2y-3=0
4x^2+4y^2+0xy-8x+24y-17=0
x^2+y^2+0xy+0x+0y-25=0
x^2+y^2+0xy+8x+4y-5=0
2x^2+2y^2+0xy-1x+3y+1=0
100x^2+100y^2+0xy-200x-400y+100=0
3x^2+3y^2+0xy+6x-24y-57=0
20000x^2+20000y^2+0xy-40000x+12000y-12000=0
x^2+y^2-0xy-8x+0y+0=0

2x^2+1.5y^2+10.6=0
25.7589x^2+30.5879y^2+10.25x+4.15y+12.75=0
25.7589x^2+10.25x+4.15y+12.75=0
x+y+10=5x^2-6y^2
*/