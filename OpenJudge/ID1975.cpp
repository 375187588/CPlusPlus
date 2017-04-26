#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iterator>
using namespace std;
char tel[100010][9],a[100010][100],d[]="2223334445556667777888999";
int n;
int compare(const void *elem1,const void *elem2)
{
    return(strcmp((char*)elem1,(char*)elem2));
}
void c()
{
    int i,j,k;
    for(i=0; i<n; i++)
    {
        for(j=0,k=0; j<strlen(a[i]); j++)
        {
            if(k==3)
                tel[i][k++]='-';
            if(a[i][j]=='-') continue;
            else if(a[i][j]>='A'&&a[i][j]<='Y')
                tel[i][k++]=d[a[i][j]-65];
            else tel[i][k++]=a[i][j];
        }
        tel[i][k]=0;
    }
}
void b()
{
    int i=0,k=1,j;
    while(i<n)
    {
        j=i,i++;
        while(i<n&&strcmp(tel[j],tel[i])==0)
            i++;
        if(i-j>1)
        {
            printf("%s %d\n",tel[j],i-j);
            k=0;
        }
    }
    if(k)
        printf("No duplicates.\n");
}
int main()
{
    scanf("%d",&n);
    int i,j;
    for(i=0; i<n; i++)
        scanf("%s",&a[i]);
    c();
    qsort(tel,n,9,compare);
    b();
}
