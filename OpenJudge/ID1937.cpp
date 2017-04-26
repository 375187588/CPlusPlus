#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    int i,j,x=0,pox,p=0,pop,popl,l;
    float xp,nump=0,w=1,num=0,sum;
    char bds[32];
    while(cin>>bds)
    {
        popl=-1,sum=0,l=strlen(bds);
        for(i=0; i<=l; ++i)
        {
            if(bds[i]=='x') x=1,pox=i;
            else if(bds[i]=='^') p=1,pop=i;
            else if(bds[i]=='+'||bds[i]=='-'||bds[i]==0)
            {
                if(x==1)
                {
                    if(p==1)
                    {
                        for(j=i-1; j>pop; --j)
                            nump+=(bds[j]-48)*w,w*=10;
                        xp=pow(3,nump),w=1,nump=0;
                    }
                    else xp=3;
                    if(pox-1==popl)
                        num=1;
                    else
                        for(j=pox-1; j>popl; --j)
                            num+=(bds[j]-48)*w,w*=10;
                    num*=xp,w=1;
                }
                else
                    for(j=i-1; j>popl; --j)
                        num+=(bds[j]-48)*w,w*=10;
                w=1;
                if(popl==-1)
                    sum+=num;
                else if(bds[popl]=='+')
                    sum+=num;
                else sum-=num;
                num=0,popl=i,p=0,x=0;
            }
        }
        cout<<(int)sum<<endl;
    }
}
