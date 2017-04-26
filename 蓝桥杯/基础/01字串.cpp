#include<bitset>
#include<iostream>
using namespace std;
int main()
{
    int x=0;
    bitset<5> bit;
    while(x<32)
    {
        bit=x;
        cout<<bit<<endl;
        x++;
    }
}
