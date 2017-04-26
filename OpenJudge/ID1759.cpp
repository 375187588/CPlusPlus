#include<iostream>
using namespace std;
int main()
{
    int n,*m,*counts;
    cin>>n;
    m=new int[n];
    counts=new int[n];
    for(int i=0; i<n; i++)
    {
        cin>>m[i];
        int temp=0;
        for(int j=i-1; j>=temp; j--)
        {
            if(m[j]<m[i]&&temp<counts[j])
                temp=counts[j];
        }
        counts[i]=temp+1;
    }
    int temp=0;
    for(int k=0; k<n; k++)
    {
        if(temp<counts[k])
            temp=counts[k];
    }
    cout<<temp<<endl;
    return 0;
}
