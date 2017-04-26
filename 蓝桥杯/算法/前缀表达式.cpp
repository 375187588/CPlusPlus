#include<iostream>
using namespace std;
int main()
{
    char c;
    int x,y;
    cin>>c>>x>>y;
    switch(c)
    {
    	case '+':
    		cout<<x+y<<endl;
    		break;
    	case '-':
    		cout<<x-y<<endl;
    		break;
    	case '*':
    		cout<<x*y<<endl;
    		break;
    	case '/':
    		cout<<x/y<<endl;
    		break;
	};
	return 0;
}
