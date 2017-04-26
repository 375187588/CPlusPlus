#include<iostream>
using namespace std;
int main()
{
	int n,tempv,v=0,c=0,mv=0,mc=0;
	cin>>n;
	while(n>0)
	{
		cin>>tempv;
		if(tempv==v)c++;
		else
		{
			if(c>mc)mc=c,mv=v;
			v=tempv,c=1;
		}
		n--;
		if(!n)
		{
			if(c>mc)mc=c,mv=v;
			v=tempv,c=1;
			cout<<mv;
		}
	}
	return 0;
}
