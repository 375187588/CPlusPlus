#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int n,i,j,o,k,x,p,z,t,y,l;
    string b,c,d;
    string a[100];
    int m[100];
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>x;
        for(y=0; y<x; y++)
        {
            cin>>a[y];
            m[y]=a[y].length();
        }
        for(y=0,l=m[0],t=0; y<x; y++)
            if(m[y]<l) l=m[y],t=y;
        for(j=l; j>0; j--)
            for(k=0; k<=l-j; k++)
            {
                c=a[t].substr(k,j);
                d=c;
                reverse(d.begin(),d.end());
                //cout<<c<<' '<<d<<endl;
                for(z=0,o=0; z<x; z++)
                    if(p=a[z].find(c)==string::npos)
                        if(p=a[z].find(d)==string::npos)
                        {
                            o++;
                            break;
                        }
                if(o==0)
                {
                    cout<<j<<endl;
                    goto sss;
                }
            }
        if(o!=0&&j==0)
            cout<<0<<endl;
sss:
        ;
    }
    return 0;
}
