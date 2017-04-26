#include<iostream>
using namespace std;
void binary(int x)
{
	int y=31;
	bool addPlus=false;
	while(x)
	{
		if(x<0) 
		{
			if(addPlus)cout<<"+";
			else addPlus=1;
			if(y==1)cout<<2;
			else if(!y)cout<<"2(0)";
			else
			{
				cout<<"2(";
				binary(y);
				cout<<")";	
			}
		}
		x<<=1;
		y--;
		
	}
}
int main()
{
	int x;
	cin>>x;
	binary(x);
	return 0;
}
