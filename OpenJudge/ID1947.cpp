#include<iostream>
using namespace std;
int main()
{
    int b[26],k,a[26],t,i,j;
    cin>>k;
    for(i=1; i<=k; i++)
        cin>>a[i];
    for(i=1; i<=k; i++)
    {
        for(j=1,t=0; j<i; j++)
            if(a[j]>=a[i])
                if(b[j]>t) t=b[j];
        b[i]=t+1;
    }
    for(i=1,t=0; i<=k; i++)
        if(b[i]>t) t=b[i];
    cout<<t;
}
