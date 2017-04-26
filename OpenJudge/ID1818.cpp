#include<iostream>
using namespace std;
int n,m;
char a[21][21];
int ww(int p,int q)
{
    if(p<0||p>=m||q<0||q>=n) return 0;
    if(a[p][q]=='#') return 0;
    else a[p][q]='#';
    return 1+ww(p-1,q)+ww(p+1,q)+ww(p,q-1)+ww(p,q+1);
}
int main()
{
    int i,j,k,p,q;
    while(cin>>n>>m&&n!=0&&m!=0)
    {
        for(i=0; i<m; i++)
            cin>>a[i];
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                if(a[i][j]=='@')
                    cout<<ww(i,j)<<endl;
    }
}
