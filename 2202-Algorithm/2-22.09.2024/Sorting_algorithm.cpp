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

class Sorting_Algorithm
{
    public:
    ll Bubble_Sort(vector<int>&A)
    {
        ll step=0;
        int n=A.size();
        step++;
        for(int i=0;i<n;i++)
        {
            step++;
            bool flag=true;
            step++;
            for(int j=0;j<n;j++)
            {
                step++;
                if(A[j]>A[j+1])
                {
                    step++;
                    swap(A[j],A[j+1]);
                    flag=false;
                }
            }
            step++;
            if(flag)
            {
                step++;
                break;
            } 
        }
        step++;
        return step;

    }
    ll Insertion_sort(vector<int>&A)
    {
        int n=A.size();
        ll step=0;
        step++;
        for (int i=1;i<n;i++)
        {
            step++;
            int value=A[i]; 
            int j=i-1;
            step=step+2;
            while (j>=0 && A[j]>value)
            {
                step++;
                A[j+1]=A[j]; 
                j=j-1;
                step=step+1;
            }
            step++;
            A[j+1]=value;
            step++;
        }
        step++;
        return step;

    }
    ll Selection_Sort(vector<int>&A)
    {
        int n=A.size();
        ll step=0;
        step++;
        for(int i=0;i<n;i++)
        {
            step++;
            int mn=i;
            int j=i+1;
            step=step+2;
            while(j<n)
            {
                if(A[j]<A[i])
                {
                    mn=j;
                    step++;
                }
                j++;
                step++;
            }
            step++;
            swap(A[i],A[mn]);
            step++;
        }
        step++;
        return step;
    }
};
void print(vector<int>A)
{
    for (int i:A)
    {
        cout<<i<<" ";
    }
    newl;
}

int main()
{
    vector<int>A[5];
    int B[5]={1000,5000,10000,15000,20000};
    for(int i=0;i<5;i++)
    {
        ifstream ip;
        ip.open("input.txt");
        for(int j=1;j<=B[i];j++)
        {
            int x;
            ip>>x;
            A[i].push_back(x);

        }
        ip.close();
    }
    Sorting_Algorithm sort=Sorting_Algorithm();
    vector<int>temp;
    ofstream op;
    op.open("output.txt");
    op<<"No. of Data\t Bubble Sort\t Selection Sort\t Insertion Sort\n";
    for(int i=0;i<5;i++)
    {
        op<<"  "<<B[i]<<"\t\t\t";
        temp=A[i];
        op<<sort.Bubble_Sort(temp)<<"\t\t";
        temp=A[i];
        op<<sort.Selection_Sort(temp)<<"\t\t";
        temp=A[i];
        op<<sort.Insertion_sort(temp)<<"\n";
    }

}