#include<cstdio>
#include<string>
#include<iterator>
#include<algorithm>
#include<sstream>
#include<iostream>
using namespace std;
struct dic
{
    string r,t;
};
bool com(dic a,dic b)
{
    if(a.t>b.t)
        return false;
    else
        return true;
}
dic y[100010];
int main()
{
    string p;
    int i,j,n=0,m,len;
    while(getline(cin,p))
    {
        if(!p[0])
            break;
        else
        {
            istringstream istrString(p);
            istrString>>y[n].r>>y[n].t;
        }++n;
    }
    sort(y,y+n,com);
    string di;
    int min,max,mid;
    while(cin>>di)
    {
        min=0,max=n-1,mid=(min+max)/2;
        while(y[mid].t!=di&&min<max)
        {
            if(di>y[mid].t)
                min=mid+1;
            else
                max=mid-1;
            mid=(min+max)/2;
        }
        if(di==y[mid].t)
            cout<<y[mid].r<<endl;
        else
            cout<<"eh"<<endl;
    }
    return 0;
}
