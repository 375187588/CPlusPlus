#include<iostream>
#include<cmath>
using namespace std;
int c=1,queen[100];
void print()
{
    int i,j;
    cout<<"No. "<<c<<endl;
    ++c;
    for(j=1; j<=8; ++j)
    {
        for(i=1; i<=8; ++i)
        {
            if(queen[i]==j)
                cout<<1<<' ';
            else
                cout<<0<<' ';
        }
        cout<<endl;
    }
}
bool place(int n)
{
    for(int i=1; i<n; i++)
    {
        if(abs(queen[n]-queen[i])==n-i||queen[n]==queen[i])
            return 0;
    }
    return 1;
}
void queens()
{
    int m,i=1,j;
    for(int k=0; k<=8; k++)
        queen[k]=0;
    while(i>=1)
    {
        ++queen[i];
        while(!place(i)&&queen[i]<=8)
            ++queen[i];
        if(queen[i]<=8&&i==8)
            print();
        else if(queen[i]<=8&&i<8)
            i++;
        else
            queen[i]=0,i--;
    }
}
int main()
{
    queens();
}
