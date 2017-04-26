#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<iomanip>
#include<sstream>
using namespace std;
string hexStr;
bool binarySet[40000];
char octStr[13334];
int main()
{
    int n;
    long long test;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        memset(binarySet,0,sizeof(binarySet));
        memset(octStr,0,sizeof(octStr));
        cin>>hexStr;
        int hexLength=hexStr.length();
        int octLength=0;
        int tempHex=0,tempOct=0;
        for(int j=hexLength-1,k=0;j>=0;j--,k+=4)
        {
            if(hexStr[j]>='0'&&hexStr[j]<='9') tempHex=hexStr[j]-'0';
            else tempHex=hexStr[j]-'A'+10;
            if(tempHex&1){
                //cout<<"0001"<<' ';
                binarySet[k]=1;}
            if(tempHex&2){
                //cout<<"0010"<<' ';
                binarySet[k+1]=1;}
            if(tempHex&4){
                //cout<<"0100"<<' ';
                binarySet[k+2]=1;}
            if(tempHex&8){
                //cout<<"1000"<<' ';
                binarySet[k+3]=1;}
        }
        for(int j=0;j<hexLength*4;)
        {
            tempOct+=binarySet[j++];
            tempOct+=binarySet[j++]*2;
            tempOct+=binarySet[j++]*4;
            //cout<<tempOct<<' ';
            octStr[octLength++]=tempOct+'0';
            tempOct=0;
        }
        while(!(octStr[octLength-1]-'0'))
        {
            octStr[octLength-1]=0;
            octLength--;
        }
        reverse(octStr,octStr+octLength);
        cout<<octStr<<endl;
    }
}
