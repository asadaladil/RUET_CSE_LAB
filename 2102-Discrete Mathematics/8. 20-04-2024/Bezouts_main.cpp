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
    cout<<"Enter 2 numbers-> ";
    int a,b;
    cin>>a>>b;
    map<int,int>res=Bezouts_coefficient(a,b);
    newl;
    cout<<"Bezouts Coefficient of "<<a<<" is "<<res[a];
    newl;
    cout<<"Bezouts Coefficient of "<<b<<" is "<<res[b];
    newl;
}
