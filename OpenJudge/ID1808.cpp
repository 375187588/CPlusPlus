#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define N 205
char a[N],b[N];
int f[N][N],l1,l2;
int main()
{
    while(scanf("%s%s",a,b)!=EOF)
    {
        l1=strlen(a);
        l2=strlen(b);
        for(int i=1; i<=l1; i++)
        {
            for(int j=1; j<=l2; j++)
            {
                if(a[i-1]==b[j-1]) f[i][j]=f[i-1][j-1]+1;
                else f[i][j]=max(f[i-1][j],f[i][j-1]);
            }
        }
        printf("%d\n",f[l1][l2]);

        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(f,0,sizeof(f));
    }
}
