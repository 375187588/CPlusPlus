#include<iostream>
using namespace std;
int C(int k,int n)
{
    if(k==0||k==n)return 1;
    else return C(k,n-1)+C(k-1,n-1);
}
int main()
{
    int k,n;
    cin>>k>>n;
    cout<<C(k,n);
}
