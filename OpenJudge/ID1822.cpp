#include<iostream>
#include<algorithm>
#include <cstring>
using namespace std;
int main()
{
    int i;
    int c[26],d[26];
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    char p[101];
    cin>>p;
    for(i=0; i<strlen(p); i++)
    {
        c[p[i]-'A']++;
    }
    cin>>p;
    for(i=0; i<strlen(p); i++)
    {
        d[p[i]-'A']++;
    }
    sort(c,c+26);
    sort(d,d+26);
    for(i=0; i<26; i++)
        if(c[i]!=d[i])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    cout<<"YES"<<endl;
    return 0;
}
