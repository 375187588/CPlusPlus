#include<cstdio>
#include<cstring>
int main()
{
    int v[1002];
    int t,m,a,b,i,j;
    while(scanf("%d %d",&t,&m)!=EOF)
    {
        memset(v,0,sizeof(v));
        for(i=1; i<=m; i++)
        {
            scanf("%d %d",&a,&b);
            if(t-a>=0)
                for(j=t-a; j>=0; j--)
                    if(v[j]+b>v[j+a])
                        v[j+a]=v[j]+b;
        }
        printf("%d\n",v[t]);
    }
    return 0;
}
