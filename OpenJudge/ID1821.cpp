#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int a[3],i,j,k,l;
    char d[101],e[101];
    while(cin>>a[0]>>a[1]>>a[2]||a[0]||a[1]||a[2])
    {
        memset(d,0,sizeof(d)),memset(e,0,sizeof(e));
        cin>>d;
        int m[3][101],n[3]= {0,0,0};
        l=strlen(d);
        for(i=0; i<l; ++i)
        {
            if(d[i]>='a'&&d[i]<='i')
                m[0][n[0]++]=i;
            else if(d[i]>='j'&&d[i]<='r')
                m[1][n[1]++]=i;
            else m[2][n[2]++]=i;
        }
        for(i=0; i<3; ++i)
        {
            k=a[i]%n[i];
            for(j=0; j<n[i]; ++j)
                e[m[i][j]]=d[m[i][(j-k+n[i])%n[i]]];
        }
        cout<<e<<endl;
    }
}
