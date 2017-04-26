#include<iostream>
#include<cstring>
#include<map>
#include<cstdio>
using namespace std;
//map<int,int> *g;
int g[20000][20000];
int n,m;
long long d[20000];
bool passed[20000];
void goahead(int s,int dis)
{
	//cout<<"s: "<<s<<" dis: "<<dis<<endl;
	if(d[s]>dis) d[s]=dis;
//	for(map<int,int>::iterator i=g[s].begin(); i!=g[s].end();i++)
//	{
//		if(!passed[i->first])
//		{
//			passed[i->first]=1,dis+=i->second;
//			goahead(i->first,dis);
//			passed[i->first]=0,dis-=i->second;
//		}
//	}
	for(int i=0;i!=n;i++)
	{
		if(!passed[i]&&g[s][i])
		{
			passed[i]=1,dis+=g[s][i];
			goahead(i,dis);
			passed[i]=0,dis-=g[s][i];
		}
	}
}
int main()
{
	int s,e,dis;
	long long t=20000*sizeof(int);
	for(int i=0;i<20000;i++)
		memset(g[i],0,t);
	memset(passed,0,t);
	for(int i=0;i<20000;i++)
		d[i]=0x7fffffff;
	cin>>n>>m;
//	g=new map<int,int>[n];
	for(int i=0;i<m;i++)
	{
		
	 	scanf("%d%d%d",&s,&e,&dis);
	 	g[s-1][e-1]=dis;
	}
	passed[0]=1;
	goahead(0,0);
	for(int i=1;i<n;i++)
	{
		printf("%d\n",d[i]);
	}
	return 0;
}
