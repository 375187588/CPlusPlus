#include<iostream>
#include<cstring>
using namespace std;
void change(int a,int b,char c[])
{
    int i,j,n,l;
    long x;
    char d[35];
    l=strlen(c);
    if(a<11)
        for(i=l-1,n=1,x=0; i>=0; i--)
        {
            x+=(c[i]-48)*n;
            n*=a;
        }
    else
        for(i=l-1,n=1,x=0; i>=0; i--)
        {
            if(c[i]<='9')
            {
                x+=(c[i]-48)*n;
                n*=a;
            }
            if(c[i]>='A')
            {
                x+=(c[i]-55)*n;
                n*=a;
            }
        }
    i=0;
    if(x>0)
        while(x>0)
            d[i++]=x%b+48,x/=b;
    else d[i++]=48;
    for(j=i-1; j>=0; j--)
    {
        if(d[j]>=58)
            d[j]+=7;
        cout<<d[j];
    }
}
int main()
{
    int a,b,i;
    char c[35];
    cin>>a>>c>>b;
    for(i=0; i<strlen(c); i++)
        if(c[i]>='a')
            c[i]-=32;
    change(a,b,c);
}
