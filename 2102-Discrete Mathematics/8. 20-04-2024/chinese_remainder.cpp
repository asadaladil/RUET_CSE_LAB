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

#include"Bezouts_coefficient.cpp"
int main()
{
    cout<<"Enter Total Congruence Relations (a,m): ";
    int n;
    cin>>n;
    ll M=1;
    int x=0;
    vector<pair<int,int>>CR;
    for(int i=1;i<=n;i++)
    {
        int a,m;
        cin>>a>>m;
        CR.push_back({a,m});
        M*=m;
    }
    for(int i=0;i<n;i++)
    {
        ll mk=M/CR[i].second;
        map<int,int>inverse=Bezouts_coefficient(CR[i].second,mk);
        x+=(CR[i].first*mk*inverse[mk]);
    }
    if(x%M<0)
    {
        x=(x%M)+M;
    }
    cout<<"The value of x is ";
    cout<<(x%M);

}
