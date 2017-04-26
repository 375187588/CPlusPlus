#include<iostream>
#include<cmath>
using namespace std;
int n,m;
void tt(int a,int b)
{
    int i;
    for(i=b; i<=n; i++)
    {
        if(a*i==n)
        {
            m++;
            break;
        }
        else if(a*i<n)
        {
            tt(a*i,i);
        }
        else if(a*i>n)break;
    }
}
int main()
{
    int r,i,s;
    cin>>r;
    for(i=0; i<r; i++)
    {
        cin>>n;
        m=0;
        tt(1,2);
        cout<<m<<endl;
    }
    return 0;
}
