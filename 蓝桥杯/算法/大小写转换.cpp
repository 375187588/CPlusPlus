#include<iostream>
using namespace std;
int main()
{
	char str[21];
	cin>>str;
	for(int i=0;str[i]!=0;i++)
	{
		if(str[i]>='a'&&str[i]<='z')
			str[i]-=32;
		else
			str[i]+=32;
	}
	cout<<str;
}
