#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<list>
#include<vector>
using namespace std;
struct node
{
	int t;
}*nodes;
struct edge
{
	int p[2], t;
	bool operator<(const edge &e)
	{
		return t<e.t;
	}
};
int n,p,*root;
bool isConn(int n1,int n2)
{
	while(root[n1]>=0) n1=root[n1];
	while(root[n2]>=0) n2=root[n2];
	return n1==n2;
}
void merge(int n1,int n2)
{
	int t=n2;
	while(root[t]>=0) t=root[t];
	root[t]=n2;
	root[n2]=n1;
}
int kruskal(list<edge>&edges)
{
	int et=0;
	for(list<edge>::iterator i=edges.begin();i!=edges.end();i++)
	{
		edge e=*i;
		if(!isConn(e.p[0],e.p[1]))
		{
			//cout<<et<<" "<<e.t<<" "<<e.p[1]<<endl;
			et+=e.t;
			merge(e.p[0],e.p[1]);
		}
	}
	return et;
}
int main()
{
	int nt=0x7fffffff,et=0;
	cin>>n>>p;
	nodes=new node[n];
	root=new int[n];
	list<edge>edges;
	for(int i=0;i<n;i++)
	{
		root[i]=-1;
		cin>>nodes[i].t;
		if(nodes[i].t<nt)nt=nodes[i].t;
	}
	int p0,p1,t;
	for(int i=0;i<p;i++)
	{
		edge e;
		cin>>p0>>p1>>t;
		t*=2,t+=nodes[p0-1].t+nodes[p1-1].t;
		e.p[0]=p0-1, e.p[1]=p1-1,e.t=t;
		edges.push_back(e);
	}
	edges.sort();
	et=kruskal(edges);
	cout<<nt+et;
	return 0;
}
