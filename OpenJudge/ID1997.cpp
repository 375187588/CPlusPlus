#include<iostream>
#include<algorithm>
#include<iterator>
using namespace std;
int main()
{
    short n,m,i;
    cin>>n>>m;
    short a[n];
    for(i=0; i<n; i++)
        cin>>a[i];
    while (m--)
        next_permutation(a,a+n);
    for(i=0; i<n; i++)
        cout<<a[i]<<' ';
    return 0;
}
