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
/*
 █████╗ ██████╗ ██╗██╗
██╔══██╗██╔══██╗██║██║
███████║██║  ██║██║██║
██╔══██║██║  ██║██║██║
██║  ██║██████╔╝██║███████╗
╚═╝  ╚═╝╚═════╝ ╚═╝╚════*/
#include<bits/stdc++.h>
using namespace std;
#define _easy_ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define str string
using vec_p=vector<pair<double,double>>;
using pr=pair<double,double>;
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
#define A_sort(x,n,y) sort(x.begin()+n,x.end(),y)
#define D_sort(x) sort(x.rbegin(),x.rend())
#define Reverse(x) reverse(x.begin(),x.end())
#define Vary(A,x,y,n) transform(A.begin()+x,A.begin()+y,A.begin()+x,[](int a){return a+n;})
#define Vary_perm(x) next_permutation(x.begin(),x.end())
#define yes_or_no cout<<"YES\n":cout<<"NO\n"
#define yess cout<<"YES\n"
#define noo cout<<"NO\n"
#define endl "\n"
#define newl cout<<endl

double p=1e10,q=1e10;
ll step;
bool compare(pr A,pr B)
{
    double angleA=atan2(A.second-q,A.first-p);
    double angleB=atan2(B.second-q,B.first-p);
    return angleA<angleB;
}
double cross_p(pr o,pr a,pr b)
{
    step++;
    return (a.first-o.first)*(b.second-o.second)-(a.second-o.second)*(b.first-o.first);
}

// using graham scan algorithm
vec_p Grahams_scan(vec_p &points)
{
    int n=points.size();
    vec_p convex_hull;
    for(int i=0;i<3;i++)
    {
        step++;
        convex_hull.push_back(points[i]);
    }
    step++;
    for(int i=3;i<n;i++)
    {
        step++;
        while(convex_hull.size()>1 && 
        cross_p(convex_hull[convex_hull.size()-2],convex_hull.back(),points[i])<=0)
        {
            step++;
            convex_hull.pop_back();
        }  
        convex_hull.push_back(points[i]);step++;
    }
    step++;
    convex_hull.push_back(points[0]);step++;
    return convex_hull;
}
int main()
{
    vector<int>value={1000,2000,5000,8000,10000,12000,15000};
    ofstream op;
    op.open("polygon.txt");
    op<<"Total Points--->Total Steps--->Total Vertices\n";
    for(int i=0;i<7;i++)
    {
        ifstream ip;
        ip.open("hull.txt");
        vec_p points;
        step=0;
        double x,y;
        int pp,j=0;
        while(ip>>x>>y)
        {
            points.push_back({x,y});
            if(q>y)
            {
                p=x;q=y;
                pp=j;
            }
            j++;
            if(j==value[i])
            {
                break;
            } 
        }
        ip.close();
        swap(points[0],points[pp]);step++;
        A_sort(points,1,compare);step+=(value[i]-1)*log2(value[i]-1);
        vec_p convex_hull=Grahams_scan(points);
        // for(auto i:convex_hull)
        // {
        //     op<<i.first<<" "<<i.second<<"\n";
        //     //cout<<i.first<<" "<<i.second<<"\n";
        // }
        op<<value[i]<<"----------->"<<step<<"----------->"<<convex_hull.size()-1<<"\n";
    }
    // ifstream ip;
    // ip.open("hull.txt");
    // int x,y;
    // while(ip>>x>>y)
    // {
    //     op<<"("<<x<<","<<y<<")\n";
    // }
    
}
/*
0 0
2 0
3 1
3 3
2 4
0 3
-1 2
0 0


0 0
1 1 
2 2
2 0
2 4
3 3
0 3
3 1
-1 2

*/