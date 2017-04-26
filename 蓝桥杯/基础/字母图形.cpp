#include<iostream>
using namespace std;
int main()
{
	int n;
	int m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int j=0;
		for(char a='A'+i;a>'A'&&j<m;a--)
		{
			cout<<a;
			j++;
		}
		for(char a='A';a<='Z'&&j<m;a++)
		{
			cout<<a;
			j++;
		}
		cout<<endl;
	}
	return 0;
}
