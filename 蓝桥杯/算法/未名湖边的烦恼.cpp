#include<iostream>
using namespace std;
int sort(int m,int n,int r)
{	
	if(!m&&!n) return 0;
	if(m<n)return 0;
	if(!m||!n) return 1;
	int x=0;
	if(m>0)
		x+=sort(m-1,n,r+1);
	if(n>0)
		x+=sort(m,n-1,r-1);
	return x;
}
int main()
{
	int m,n;
	cin>>m>>n;
	cout<<sort(m,n,0);
	return 0;
}
