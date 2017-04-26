#include<iostream>
#include<cmath>
using namespace std;
int n,m,o;
void tt(int a,int b,int c)
{
    int i;
    for(i=b; i<=n; i++)
    {
        if(c<=o)
        {
            if(a+i==n)
            {
                m++;
                break;
            }
            else if(a+i<n)
                tt(a+i,i,c+1);
        }
        else break;
    }
}
int main()
{
    int r,i,s;
    cin>>r;
    for(i=0; i<r; i++)
    {
        cin>>n>>o;
        m=0;
        if(o>n) o=n;
        tt(0,1,1);
        cout<<m<<endl;
    }
    return 0;
}
