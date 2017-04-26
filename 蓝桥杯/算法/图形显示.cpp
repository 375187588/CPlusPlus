#include<iostream>
using namespace std;
void printOut(int n)
{
	for(int i=n;i>0;i--)
	{
		for(int j=0;j<i;j++)
		
			cout<<(j?" *":"*");
		if(i-1)cout<<endl;
	}
}
int main()
{
	int n;
	cin>>n;
	printOut(n);
	return 0;
 } 
