#include<iostream>
using namespace std;
long long lcm(long long m,long long n)
{
    long long maxNum=(m>=n?m:n),minNum=(m>=n?n:m);
    for(long long i=1;i<=minNum;i++)
        if(i*maxNum%minNum==0)
            return i*maxNum;
}
int main()
{
    long long m,n;
    cin>>m>>n;
    cout<<lcm(m,n);
}
