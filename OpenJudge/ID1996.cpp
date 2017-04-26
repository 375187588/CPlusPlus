#include<iostream>
using namespace std;
int main()
{
    int *m,n,*interestsup,*interestsdown,*flag,sum=0;
    cin>>n;
    m=new int[n];
    interestsup=new int[n];
    interestsdown=new int[n];
    for(int i=0; i<n; i++)
        cin>>m[i];
    for(int i=0; i<n; i++)
    {
        int interest=0;
        for(int j=i-1; j>=0; j--)
            if(m[j]<m[i]&&interest<interestsup[j])
                interest=interestsup[j];
        interestsup[i]=interest+1;
    }
    for(int i=n-1; i>=0; i--)
    {
        int interest=0;
        for(int k=i+1; k<n; k++)
            if(m[k]<m[i]&&interest<interestsdown[k])
                interest=interestsdown[k];
        interestsdown[i]=interest+1;
    }
    for(int i=0; i<n; i++)
    {
        if(sum<interestsup[i]+interestsdown[i])
            sum=interestsup[i]+interestsdown[i];
    }
    cout<<sum-1;
    return 0;
}
