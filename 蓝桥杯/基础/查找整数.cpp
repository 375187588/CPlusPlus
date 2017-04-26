#include<iostream>
using namespace std;
int main()
{
    int m;
    int *numArray;
    int aimNumber;
    cin>>m;
    numArray=new int[m];
    for(int i=0;i<m;i++)
    {
        cin>>numArray[i];
    }
    cin>>aimNumber;
    bool existed=0;
    for(int i=0;i<m;i++)
    {
        if(numArray[i]==aimNumber)
        {
            cout<<i+1;
            existed=1;
            break;
        }
    }
    if(!existed)cout<<-1;
}
