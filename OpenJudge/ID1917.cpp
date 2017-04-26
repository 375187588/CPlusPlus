#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iterator>
using namespace std;
int main()
{
    int n,i,j,k,m;
    while(cin>>n)
    {
        getchar();
        int b[n];
        char a[n][101],c[101];
        for(i=0; i<n; i++)
        {
            gets(a[i]);
            b[i]=strlen(a[i]);
            if(!strcmp(a[i],"stop")) break;
        }
        for(j=0; j<i-1; j++)
            for(k=0; k<i-1-j; k++)
                if(b[k]>b[k+1])
                {
                    m=b[k],b[k]=b[k+1],b[k+1]=m;
                    strcpy(c,a[k]),strcpy(a[k],a[k+1]),strcpy(a[k+1],c);
                }
        for(j=0; j<i; j++)
            cout<<a[j]<<endl;
    }
}
