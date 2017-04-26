#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,m,i,j,l,r,k,*a,*t;
	cin>>n;
	a=new int[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	cin>>m;
	vector<int> *tA;
	while(m)
	{
		cin>>l>>r>>k;
		t=new int[r-l+1];
		for(i=l-1,j=0;i<r;i++,j++)
			t[j]=a[i];
		sort(t,t+j);
		cout<<t[j-k]<<endl;
		delete[] t;
		m--;
	}
	return 0;
}
	
