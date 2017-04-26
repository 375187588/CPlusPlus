#include<iostream>
using namespace std;
int main() 
{
	int n,temp,temp0,temp1,max=0;
	cin>>n;
	int node[2][n];
	cin>>node[0][0];
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=i;j++)
			cin>>node[1][j];
			temp0=0;
		for(int j=0;j<i;j++)
		{
			temp=node[0][j];
			temp1=temp+node[1][j];
			node[0][j]=temp1>temp0?temp1:temp0;
			(j+1==i?node[0][j+1]:temp0)=temp+node[1][j+1];
		}
	}
	for(int i=0;i<n;i++)
		max=max>node[0][i]?max:node[0][i];
	cout<<max;
}
