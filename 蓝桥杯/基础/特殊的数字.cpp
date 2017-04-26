#include<iostream>
using namespace std;
int shuixianhuashu(int m)
{
    int minNumber=1;
    int maxNumber=10;
    int temp,tempSum;
    for(int i=0;i<m-1;i++)
    {
        minNumber*=10;
        maxNumber*=10;
    }
    for(int i=minNumber;i<maxNumber;i++)
    {
        int x=i;
        tempSum=0;
        while(x)
        {
            temp=x%10;
            tempSum+=temp*temp*temp;
            x/=10;
        }
        if(tempSum==i)
        {
            cout<<i<<endl;
        }
    }
}
int main()
{
    shuixianhuashu(3);
}
