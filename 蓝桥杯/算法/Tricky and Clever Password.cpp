#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int *next;
int *preSufLength;
int *preSufLongestEnd;
int *midLength;
void getMid(char* s,int length)
{
    int i,k,l;
    for(i=0;i<length;i++)
    {
        for(k=l=i;k>=0&&l<length;k--,l++)
        {
            if(s[k]==s[l])midLength[i]++;
            else break;
        }
    }
}
void getNext(char* s,int length)
{
    int i=length-1,j=length-1;
    next[i--]=length-1;
    for(;i>=0;)
    {
        if(s[j]==s[i])
            next[i]=j--,i--;
        else if(j==length-1)next[i]=j,i--;
        else j=next[j];
    }
}
void getPreSuf(char* s,int length)
{
    for(int i=0,j=length-1;i<=length;)
    {
        if(j-i<2||s[i]!=s[j])
        {
            if(j==length-1)
            {
                i++;
                continue;
            }
            else
                j=next[j+1];
        }
        else
        {
            preSufLength[i]>=length-j?:preSufLength[i]=length-j;
            i++,j--;
        }
    }
}
void transform_preSufLength(int length)
{
    int i,tempLen,tempPreEnd,tempSufLen;
    for(i=0,tempLen=-1,tempPreEnd=0,tempSufLen=length-1;tempLen<tempSufLen&&i<length-1;i++,tempSufLen--)
    {
        if(tempLen<preSufLength[i])
            tempLen=preSufLength[i],tempPreEnd=i;
        preSufLength[i]=tempLen,preSufLongestEnd[i]=tempPreEnd;
    }
    for(;i<length-1;i++,tempLen--,tempPreEnd--)
    {
        preSufLength[i]=tempLen,preSufLongestEnd[i]=tempPreEnd;
    }
}
void getResult(int length,int& pre,int& mid,int& suf,int& preSufLen,int& midLen)
{
    int tempLen=0,tempPreLen=0,tempSufLen=0,tempMidLen=0;
    for(int i=0;i<length;i++)
    {
        tempMidLen=midLength[i]+midLength[i]-1;
        if(i-midLength[i]<0||i+midLength[i]>=length)
        {
            tempPreLen=tempSufLen=0;
            tempLen=tempMidLen;
        }
        else
        {
            tempPreLen=preSufLength[i-midLength[i]];
            tempSufLen=length-i-midLength[i]+1;
            tempLen=tempMidLen+(tempPreLen>tempSufLen?tempSufLen+tempSufLen:tempPreLen+tempPreLen);
        }
        if(tempLen>midLen+preSufLen+preSufLen||tempMidLen==tempLen&&tempLen==midLen+preSufLen+preSufLen)
        {
            midLen=tempMidLen;
            preSufLen=tempPreLen>tempSufLen?tempSufLen:tempPreLen;
            mid=i-midLength[i]+2;
            suf=length-preSufLen+1;
            pre=preSufLongestEnd[i]-preSufLength[i]+2;
        }
        if(length-i<=(midLen>>1)+preSufLen)
            break;
    }
}
void process(char* s)
{
    int length=strlen(s);
    next=new int[length];
    preSufLength=new int[length];
    preSufLongestEnd=new int[length];
    midLength=new int[length];
    memset(preSufLength,0,length*sizeof(int));
    memset(midLength,0,length*sizeof(int));
    getNext(s,length);
    getPreSuf(s,length);
    getMid(s,length);
    transform_preSufLength(length);
    int pre,mid,suf,preSufLen=0,midLen=0;
    getResult(length,pre,mid,suf,preSufLen,midLen);
    if(!preSufLen)
        cout<<1<<endl<<mid<<" "<<midLen;
    else
        cout<<3<<endl<<pre<<" "<<preSufLen<<endl<<mid<<" "<<midLen<<endl<<suf<<" "<<preSufLen;
}
int main()
{
    char s[100010];
    cin>>s;
    process(s);
    return 0;
}
