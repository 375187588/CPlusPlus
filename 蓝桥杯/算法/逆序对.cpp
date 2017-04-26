#include<iostream>
using namespace std;
struct bnode
{
	int v,c;
	bnode *lc,*rc;
	bnode(int x){v=x,c=1,lc=rc=NULL;};
};
	int max(int x,int y)
	{
		if(x>y)return x;
		return y; 
	}
	int count(bnode *bn)
	{
		if(bn==NULL)
			return 0;
		return count(bn->rc)+count(bn->lc)+bn->c;
	}
	int height(bnode *bn)
	{
		if(bn==NULL)
			return 0;
		int l=height(bn->lc);
		int r=height(bn->rc);
		return (l>=r?l:r)+1;
	}
	bnode *lla(bnode *bn)
	{
		bnode *tn=bn->lc;
		bn->lc=tn->rc;
		tn->rc=bn;
		return tn;
	}
	bnode *rra(bnode *bn)
	{
		bnode *tn=bn->rc;
		bn->rc=tn->lc;
		tn->lc=bn;
		return tn;
	}
	bnode *lra(bnode *bn)
	{
		bn->lc=(bn->lc);
		return lla(bn);
	}
	bnode *rla(bnode *bn)
	{
		lla(bn->rc);
		return rra(bn);
	}
	bnode *adjust(bnode *bn)
	{
		int h=height(bn->lc)-height(bn->rc);
		if(h>1)
		{
			if(height(bn->lc->lc)>height(bn->lc->rc))
				return lla(bn);
			else 
				return lra(bn);
		}
		else if(h<-1)
		{
			if(height(bn->rc->rc)>height(bn->rc->lc))
				return rra(bn);
			else
				return rla(bn);
		}
		else 
		return bn;
	}
	bnode *insert(int x,bnode *bn)
	{
		if(bn==NULL)
		{
			bn=new bnode(x);
		}
		else if(x==bn->v)
		{
			bn->c++;
		}
		else if(x<bn->v)
		{
			bn->lc=insert(x,bn->lc);
			bn=adjust(bn);
		}
		else 
		{
			bn->rc=insert(x,bn->rc);
			bn=adjust(bn);
		}
		return bn;
	}
	int countBigger(bnode *bn,int x)
	{
		int c=0;
		bnode *b=bn;
		while(b!=NULL)
		{
			if(x<b->v) c+=b->c+count(b->rc),b=b->lc;
			else if(x==b->v)c+=b->c+count(b->rc),b=NULL;
			else b=b->rc;
		}
		return c;
	}
	bnode *merge(bnode *ln,bnode *rn)
	{
		if(rn->lc)
			ln=merge(ln,rn->lc);
		if(rn->rc)
			ln=merge(ln,rn->rc);
		return insert(rn->v,ln);
	}
	void destroy(bnode *bn)
	{
		if(bn->lc)
			destroy(bn->lc);
		if(bn->rc)
			destroy(bn->rc);
		delete bn;
	}
	void mid(bnode *bn)
	{
		if(bn->lc)
			mid(bn->lc);
		cout<<bn->v<<" ";
		if(bn->rc)
			mid(bn->rc);
	}
void calculate(bnode *ln,bnode *rn,int &l,int &r)
{
	int t=countBigger(ln,rn->v);
	int c=count(ln);
	l+=t,r+=c-t;
	if(rn->lc)
		calculate(ln,rn->lc,l,r);
	if(rn->rc)
		calculate(ln,rn->rc,l,r);
}
bnode *process(int &n,int &c)
{
	int v,l=0,r=0;
	bnode *lt,*rt,*temp;
	if(c)
	{
		cin>>v;
		if(v)
		{
			c--;
			lt=new bnode(v);
			return lt;
		}
		else 
		{
			lt=process(n,c);
			rt=process(n,c);
		}
		if(rt==NULL)
			return lt;
		if(count(rt)>count(lt))
			temp=rt,rt=lt,lt=temp;
		calculate(lt,rt,l,r);
		n+=(l<r?l:r);
		if(c)
			lt=merge(lt,rt);
		destroy(rt);
		return lt;
	}
}
int main()
{
	int c,n=0;
	cin>>c;
	process(n,c);
	cout<<n;
	return 0;
}
