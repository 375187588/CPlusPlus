#include<iostream>
#include<cstdio>
using namespace std;
struct thread
{
    int n;
    int i;
}thr[100];
int m,f,sn=0;
void sortThread()
{
    struct thread temp;
    for(int i=0;i<m-1;i++)
        for(int j=i+1;j<m;j++)
            if(thr[i].n>thr[j].n)
                temp=thr[i],thr[i]=thr[j],thr[j]=temp;
}
void display(int i)
{
    if(thr[i].i)
    {
        cout<<thr[i].i<<" ";
        thr[i].n--;
    }
}
void mt()
{
    sortThread();
    if(f>sn)
    {
        cout<<"No"<<endl;
    }
    else if(f==2&&thr[0].n!=2)
        cout<<"No"<<endl;
    else if(m&&!f)
        cout<<"No"<<endl;
    else
    {
        if(m==1&&f!=sn)
            cout<<"No"<<endl;
        else if(f<thr[0].n)
            {
            cout<<"Yes"<<endl;
            int temp=thr[0].n-f+2;
            display(1);
            for(int j=0;j<temp;j++)
                display(0);
            display(1);
            display(0);
            for(int i=1,j=0;i<m;j++)
            {
                if(!thr[i].n)
                    i++;
                display(i);
            }
            for(int j=0;j<f-2-1;j++)
                display(0);
        }
        else
        {
            cout<<"Yes"<<endl;
            display(0);
            int temp=sn-f;
            for(int i=m-1,j=0;j<temp;j++)
            {
                if(!thr[i].n)
                    i--;
                display(i);
            }
            for(int i=0,j=0;j<f-1;j++)
            {
                if(!thr[i].n)
                    i++;
                display(i);
            }
        }
    }
}
int main()
{
    int temp;
    scanf("%d%d",&m,&f);
    f*=2;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&(temp));
        thr[i].n=temp+temp;
        thr[i].i=i+1;
        sn+=thr[i].n;
    }
    mt();
}
