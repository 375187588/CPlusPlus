#include<iostream>
#include<cstdio> 
#include<cstring>
using namespace std;
struct Node
{
	int l,r,p,s;
	Node *lc,*rc;
}; 
class Tree
{
	Node *root;
	Node *init(int l,int r);
	int max(int l,int r,Node *root);
	int sum(int l,int r,Node *root);
	void change(int p,int v,Node *root);
public:
	Tree(){}
	Tree(int n){root=init(1,n);}
	void init(int n){root=init(1,n);}
	int max(int l,int r){return max(l,r,root);}
	int sum(int l,int r){return sum(l,r,root);}
	void change(int p,int v){return change(p,v,root);}
};
Node *Tree::init(int l,int r)
{
	Node *root=new Node;
	root->l=l,root->r=r;
	if(l==r)
	{
		cin>>root->p;
		root->s=root->p;
	}
	else
	{
		root->lc=init(l,(l+r)/2);
		root->rc=init(1+(l+r)/2,r);
		root->p=(root->lc->p>root->rc->p?root->lc->p:root->rc->p);
		root->s=root->lc->s+root->rc->s;
	}
	return root;
}
int Tree::max(int l,int r,Node *root)
{
	if(root->l==l&&root->r==r)
		return root->p;
	else
	{
		int m=(root->l+root->r)/2;
		if(r<=m)
			return max(l,r,root->lc);
		else if(l>m)
			return max(l,r,root->rc);
		else
		{
			int templ,tempr;
			templ=max(l,m,root->lc);
			tempr=max(m+1,r,root->rc);
			return templ>tempr?templ:tempr; 
		} 
	}
}
int Tree::sum(int l,int r,Node *root)
{
	if(root->l==l&&root->r==r)
		return root->s;
	else
	{
		int m=(root->l+root->r)/2;
		if(r<=m)
			return sum(l,r,root->lc);
		else if(l>m)
			return sum(l,r,root->rc);
		else
			return sum(l,m,root->lc)+sum(m+1,r,root->rc);
	}
}
void Tree::change(int p,int v,Node *root)
{
	if(root->l==p&&root->r==p)
		root->p=root->s=v;
	else
	{
		int m=(root->l+root->r)/2;
		if(p<=m)
			change(p,v,root->lc);
		else if(p>m)
			change(p,v,root->rc);
		root->p=(root->lc->p>root->rc->p?root->lc->p:root->rc->p);
		root->s=root->lc->s+root->rc->s;
	}
}
int main()
{
	int m,n,op,temp1,temp2;
	cin>>m>>n;
	Tree t(m);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&op,&temp1,&temp2);
		if(op==1)
			t.change(temp1,temp2);
		else if(op==2)
			printf("%d\n",t.sum(temp1,temp2));
		else
			printf("%d\n",t.max(temp1,temp2));
	}
	return 0;
}
