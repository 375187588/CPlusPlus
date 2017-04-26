#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
struct question
{
	int sientistNum;
	long long sourceNeed;
	question next(long long& x,long long& y,long long& m,bool& less)
	{
		question tempQ;
		tempQ.sientistNum=sientistNum;
		tempQ.sourceNeed=(sourceNeed*x+y)%m;
		less=tempQ.sourceNeed<sourceNeed;
		return tempQ;
	}
	bool operator<(question& q)
	{
		if(sourceNeed<q.sourceNeed)
			return 1;
		else if(sourceNeed==q.sourceNeed&&sientistNum<q.sientistNum)
			return 1;
		else
			return 0;
	}
};
int main()
{
	long long sCount,qCount,x,y,m,sqCount=0,badCount=0;
	bool less;
	question** questions;
	question* final;
	queue<int>* badPoint;
	cin>>sCount;
	questions=new question*[sCount];
	badPoint=new queue<int>[sCount];
	for(int i=0;i<sCount;i++)
	{
		cin>>qCount;
		questions[i]=new question[qCount];
		question tempQ;
		tempQ.sientistNum=i;
		sqCount+=qCount;
		cin>>tempQ.sourceNeed>>x>>y>>m;
		questions[i][0]=tempQ;
		for(int j=1;j<qCount;j++)
		{
			questions[i][j]=questions[i][j-1].next(x,y,m,less);
			if(less)
			{
				badPoint[i].push(j);
			}
		}
		if(badPoint[i].size()>badCount)
			badCount=badPoint[i].size();
		badPoint[i].push(qCount);
	}
	cout<<badCount<<endl;
	if(sqCount<=200000)
	{
		final=new question[sqCount];
		bool notFinish=1;
		int qBegin[sCount],bfInsert=0,afInsert=0; 
		memset(qBegin,0,sCount*sizeof(long long));
		while(notFinish)
		{
			notFinish=0;
			for(int i=0;i<sCount;i++)
			{
				if(!badPoint[i].empty())
				{
					for(int j=qBegin[i];j<badPoint[i].front();j++,afInsert++)
					{
						final[afInsert]=questions[i][j];
					}
					qBegin[i]=badPoint[i].front();
					badPoint[i].pop();
				}
				notFinish=notFinish||(!badPoint[i].empty());
			}
			sort(final+bfInsert,final+afInsert);
			bfInsert=afInsert;
			badCount+=1;
		}
		for(int i=0;i<sqCount;i++)
		{
			cout<<final[i].sourceNeed<<" "<<final[i].sientistNum+1<<endl;
		}
	}
	return 0;
}
