#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
void replace(char s[],char a[],char b[])
{
    int n,m,i,j,o,p;
    char ss[51][101];
    n=strlen(s);
    for(i=0,j=0,m=0; i<n; i++)
    {
        if(s[i]!=' '&&s[i]!=0)
        {
            if(s[i+1]!=0&&s[i+1]!=' ')
                ss[m][j++]=s[i];
            else
                ss[m++][j]=s[i],j=0;
        }
    }
    for(i=0; i<m; i++)
    {
        if(!strcmp(ss[i],a))
            cout<<b;
        else cout<<ss[i];
        if(m-1-i) cout<<' ';
    }
}
int main()
{
    char s[101],a[101],b[101];
    gets(s);
    cin>>a>>b;
    replace(s,a,b);
}
