#include<iostream>
using namespace std;
int huiwenshu(int m)
{
    int* temp;
    temp=new int[m];
    for(int i=1;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            temp[0]=temp[m-1]=i;
            temp[1]=temp[m-2]=j;
            for(int l=m-1;l>=0;l--)
            {
                cout<<temp[l];
            }
            cout<<endl;
        }
    }
}
int main()
{
    huiwenshu(4);
}
