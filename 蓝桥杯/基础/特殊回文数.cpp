#include<iostream>
using namespace std;
int huiwenshu(int m,int n)
{
    int* temp;
    temp=new int[m];
    for(int i=1;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                temp[0]=temp[m-1]=i;
                temp[1]=temp[m-2]=j;
                temp[2]=temp[m-3]=k;
                int sum=0;
                for(int l=0;l<m;l++)
                {
                    sum+=temp[l];
                }
                if(sum==n)
                {
                    for(int l=m-1;l>=0;l--)
                    {
                        cout<<temp[l];
                    }
                    cout<<endl;
                }

            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    if(n>45&&!(n%2))
    {
        huiwenshu(6,n);
    }
    else if(n<=45&&n%2)
    {
        huiwenshu(5,n);
    }
    else if(n<=45&&!(n%2))
    {
        huiwenshu(5,n);
        huiwenshu(6,n);
    }
}
