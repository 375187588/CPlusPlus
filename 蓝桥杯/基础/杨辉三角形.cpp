#include<iostream>
using namespace std;
int yanghuisanjiao(int m)
{
    int *numArray;
    numArray=new int[(m*m+m)/2];
    int temp=0;
    for(int i=0;i<m;i++)
    {
        if(i)cout<<endl;
        for(int j=0;j<=i;j++)
        {
            if(j==0||j==i)
            {
                temp=numArray[(i*i+i)/2+j]=1;
            }
            else
            {
                temp=numArray[(i*i+i)/2+j]=numArray[(i*i-i)/2+j]+numArray[(i*i-i)/2+j-1];
            }
            if(j)cout<<" ";
            cout<<temp;
        }
    }
}
int main()
{
    int m;
    cin>>m;
    yanghuisanjiao(m);
}
