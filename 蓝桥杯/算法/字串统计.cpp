#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int passed[60],appear[60],l,length,p,s,n;
char str[60];
void calculate()
{
	length=strlen(str);
	memset(passed,0,60*4);
	int i=0;
	n=0,s=0;
	while(i!=length-l+1)
	{
		if(!passed[i])
		{
			memset(appear,0,60*4);
			int ts=0,tn=0;
			for(int j=i;j<length;j++)
			{
				for(int k=0;k<length-j;)
				{
					if(str[i+k]==str[j+k])
					{
						appear[++k]++;
						if(k>=l&&(appear[k]>tn||appear[k]==tn&&k>ts))
							tn=appear[k],ts=k;
					}
					else break;
				}
//				cout<<"tn="<<tn<<" ts="<<ts<<endl;
			}
			if(tn>n||tn==n&&ts>s)
				n=tn,s=ts,p=i;
//			cout<<"n="<<n<<" s="<<s<<endl;
		}
		i++;
	}
	for(i=0;i<s;i++)
		cout<<str[p+i];
}
int main()
{
	cin>>l;
	cin>>str;
	calculate();
	return 0;
}
