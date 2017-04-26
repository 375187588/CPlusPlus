#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double PI=3.14159265358979323;
    double r;
    double area;
    cin>>r;
    area=r*r*PI;
    cout<<setprecision(7)<<setiosflags(ios::fixed)<<area;
}
