#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int m,n,out,in;
	cin>>m>>n;
	int g[m][n];
	memset(g,0,m*n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		cin>>out>>in;
		g[out-1][i]=1,g[in-1][i]=-1;
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cout<<g[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
