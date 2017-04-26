#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
double tt()
{
    char a[11];
    cin>>a;
    if(a[0]=='+')return tt()+tt();
    else if(a[0]=='-')return tt()-tt();
    else if(a[0]=='*')return tt()*tt();
    else if(a[0]=='/')return tt()/tt();
    else return atof(a);
}
int main()
{
    cout<<fixed<<setprecision(6)<<tt();
    return 0;
}
