#include<iostream>
#include<list>
#include<cstdio>
using namespace std;
struct node
{
	int p,maxE,maxI;
	list<int> next;
}* nodes;
int n;
void getmax(int pre,int cur)
{
	int tempe,tempi;
	node &n=nodes[cur];
	if(n.next.size()==1&&pre>0)
		n.maxE=0,n.maxI=n.p;
	else 
	{
		tempe=tempi=0;
		for(list<int>::iterator it=n.next.begin();it!=n.next.end();it++)
		{
			if(*it!=pre)
			{
				getmax(cur,*it);
				tempe+=(nodes[*it].maxE>nodes[*it].maxI?nodes[*it].maxE:nodes[*it].maxI);
				tempi+=nodes[*it].maxE;
			}
		}
		n.maxE=tempe,n.maxI=tempi+n.p;
	}
}
int main()
{
	cin>>n;
	nodes=new node[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&nodes[i].p);
	}
	int n1,n2;
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&n1,&n2);
		nodes[n1-1].next.push_back(n2-1);
		nodes[n2-1].next.push_back(n1-1);
	}
	getmax(-1,0);
	cout<<(nodes[0].maxE>nodes[0].maxI?nodes[0].maxE:nodes[0].maxI);
	return 0;
}
