#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int temp;
    int minNum;
    int maxNum;
    int sum=0;
    cin>>temp;
    sum+=temp;
    minNum=temp;
    maxNum=temp;
    for(int i=1;i<n;i++)
    {
        cin>>temp;
        sum+=temp;
        if(temp<minNum) minNum=temp;
        if(temp>maxNum) maxNum=temp;
    }
    cout<<maxNum<<endl<<minNum<<endl<<sum;
}
