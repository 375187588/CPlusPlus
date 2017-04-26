#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int m,n,sum,*x,*y;
	cin>>m;
	while(m--)
	{
		cin>>n;
		sum=0;
		x=new int[n];
		y=new int[n];
		for(int i=0;i<n;i++)
			cin>>x[i];
		for(int i=0;i<n;i++)
			cin>>y[i];
		sort(x,x+n);
		sort(y,y+n);
		for(int i=0;i<n;i++)
			sum+=x[i]*y[n-1-i];
		cout<<sum<<endl;
		delete[] x,delete[] y; 
	}
}
