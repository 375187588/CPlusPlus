#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    double a,b,x,y,x1,x2;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        x1=-a,x2=0;
        while(1)
        {
            x=(x1+x2)/2,y=x*x*x+x+a;
            if(x2-x1>=b)
            {
                if(y>0) x2=x;
                else if(y<0) x1=x;
                else break;
            }
            else break;
        }
        cout<<fixed<<setprecision(6)<<x<<' '<<y<<endl;
    }
}
