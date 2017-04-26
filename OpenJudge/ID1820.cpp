# include<iostream>
# include<cstdio>
# include<cstring>
using namespace std;
int main()
{
    int k,n,i,m,j,t,r[210],e;
    char b[210],c[210];
    while(cin>>n&&n)
    {
        int a[n];
        for(i=0; i<n; ++i)
        {
            cin>>a[i];
            --a[i];
        }
        for(i=0; i<n; ++i)
        {
            t=a[i],r[i]=0;
            while(a[t]!=a[i])
            {
                t=a[t];
                ++r[i];
            }
            ++r[i];
        }
        while(cin>>k&&k)
        {
            getchar();
            gets(b);
            if(strlen(b)<n)
            {
                for(i=strlen(b); i<n; ++i)
                    b[i]=' ';
            }
            for(i=0; i<n; ++i)
            {
                m=k%r[i];
                e=i;
                for(j=0; j<m; ++j)
                    e=a[e];
                c[e]=b[i];
            }
            c[n]=0;
            cout<<c<<endl;
        }
        cout<<endl;
    }
    return 0;
}
