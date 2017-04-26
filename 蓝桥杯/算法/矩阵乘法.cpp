#include<iostream>
using namespace std;
int **matrixMultiply(int **m1,int **m2,int x,int y,int z)
{
	int temp,i,j,k;
	int **m=new int*[x];
	for(i=0;i<x;i++)
	{
		m[i]=new int[z];
		for(j=0;j<z;j++)
		{
			temp=0;
			for(k=0;k<y;k++)
				temp+=m1[i][k]*m2[k][j];
			m[i][j]=temp;
		}
	}
	return m;
}
int main()
{
	int **m1,**m2,**m,x,y,z,i,j;
	cin>>x>>y>>z;
	m1=new int*[x];
	m2=new int*[y];
	for(i=0;i<x;i++)
	{
		m1[i]=new int[y];
		for(j=0;j<y;j++)
			cin>>m1[i][j];
	}
	for(i=0;i<y;i++)
	{
		m2[i]=new int[z];
		for(j=0;j<z;j++)
			cin>>m2[i][j];
	} 
	m=matrixMultiply(m1,m2,x,y,z);
	for(i=0;i<x;i++)
	{
		if(i) cout<<endl;
		for(j=0;j<z;j++)
		{
			if(j)cout<<" ";
			cout<<m[i][j];
		}
	}
	return 0;
}
