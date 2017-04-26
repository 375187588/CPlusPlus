#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int k,l,h,i,j,tempi;
	long long r=0;
	cin>>k>>l;
	long long t[l][k];
	memset(t,0,k*l*8);
	for(i=1;i<k;i++)
	{
		t[0][i]=1;
	}
	for(i=0;i<l-1;i++)
	{
		tempi=i+1;
		for(j=0;j<k;j++)
		{
			t[tempi][j]+=t[i][j];
			for(h=j-2;h>=0;h--)
				t[tempi][h]+=(t[i][j]>=1000000007?t[i][j]%1000000007:t[i][j]);
			for(h=j+2;h<k;h++)
				t[tempi][h]+=(t[i][j]>=1000000007?t[i][j]%1000000007:t[i][j]);
		}
	}
	for(j=0;j<k;j++)
	{
		r+=t[i][j];
		if(r>=1000000007)r%=1000000007;
	}
	cout<<r;
	return 0;
}
