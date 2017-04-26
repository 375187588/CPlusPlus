#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int i,j,m,n,k,c[300],p;
    char a[300],b[300];
    while(cin>>a>>b)
    {
        m=strlen(a),n=strlen(b);
        if(m==n)
        {
            for(i=0; i<m; i++)
                c[i]=0;
            for(i=0,p=0; i<m; i++)
            {
                if(a[i]>b[i])
                {
                    p++;
                    break;
                }
                if(a[i]<b[i])
                {
                    p--;
                    break;
                }
            }
            if(p==0) cout<<0<<endl;
            else
            {
                if(p==1)
                {
                    for(i=m-1,j=0; i>=0; i--,j++)
                    {
                        c[j]+=a[i]-b[i];
                        if(c[j]<0) c[j+1]--,c[j]+=10;
                    }
                    for(i=m-1; i>0; i--)
                    {
                        if(c[i]==0) continue;
                        if(c[i]!=0)
                            for(j=i; j>0; j--)
                                cout<<c[j];
                        break;
                    }
                    cout<<c[0]<<endl;
                }
                if(p==-1)
                {
                    for(i=m-1,j=0; i>=0; i--,j++)
                    {
                        c[j]+=b[i]-a[i];
                        if(c[j]<0) c[j+1]--,c[j]+=10;
                    }
                    cout<<'-';
                    for(i=m-1; i>0; i--)
                    {
                        if(c[i]==0) continue;
                        if(c[i]!=0)
                            for(j=i; j>0; j--)
                                cout<<c[j];
                        break;
                    }
                    cout<<c[0]<<endl;
                }
            }
        }
        else
        {
            if(m>n)
            {
                for(i=0; i<m; i++)
                    c[i]=0;
                k=m-n;
                for(i=m-1,j=0; i>=0; i--,j++)
                {
                    if(i>=k)
                        c[j]+=a[i]-b[i-k];
                    else c[j]+=a[i]-48;
                    if(c[j]<0) c[j+1]--,c[j]+=10;
                }
                for(i=m-1; i>=0; i--)
                    cout<<c[i];
                cout<<endl;
            }
            else
            {
                for(i=0; i<n; i++)
                    c[i]=0;
                k=n-m;
                for(i=n-1,j=0; i>=0; i--,j++)
                {
                    if(i>=k)
                        c[j]+=b[i]-a[i-k];
                    else c[j]+=b[i]-48;
                    if(c[j]<0) c[j+1]--,c[j]+=10;
                }
                cout<<'-';
                for(i=n-1; i>=0; i--)
                    cout<<c[i];
                cout<<endl;
            }
        }
    }
}
