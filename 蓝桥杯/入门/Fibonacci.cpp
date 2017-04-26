#include<iostream>
using namespace std;
int main()
{
    int n;
    int fn1=1,fn2=1;
    cin>>n;
    if(n>2)
    {
        int temp;
        for(int i=3;i<=n;i++)
        {
            temp=fn2;
            fn2=(temp+fn1)%10007;
            fn1=temp;
        }
    }
    cout<<fn2;
}
