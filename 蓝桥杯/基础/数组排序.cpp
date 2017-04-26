#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    int array_[200];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>array_[i];
    }
    sort(array_,array_+n);
    for(int i=0;i<n;i++)
    {
        if(i)cout<<" ";
        cout<<array_[i];
    }
}
