#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
long long n,k,data[16][16];
int main()
{
	memset(data,0,16*8);
	cin>>n>>k;
	long long m=n-k-1,temp;
	for(int i=1;i<=n;i++)
	{
		cin>>temp;
		data[i][0]=data[i-1][0]+temp;
	}
	for(int i=2;i<=n;i++)
	{
		temp=min(i,k);
		for(int j=1;j<=temp;j++)
			for(int l=j+1;l<=i;l++)
				data[i][j]=max(data[i][j],data[l-1][j-1]*(data[i][0]-data[l-1][0]));
		
	}
	cout<<data[n][k];
}

