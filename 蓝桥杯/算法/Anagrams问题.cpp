#include<iostream>
#include<cstring>
using namespace std;
void processStr(char* str,int* table)
{
	for(int i=0;str[i]!=0;i++)
	{
		if(str[i]>='a')
			table[str[i]-'a']++;
		else
			table[str[i]-'A']++;
	}
} 
bool compareStr(int table[2][26])
{
	for(int i=0;i<26;i++)
	{
		if(table[0][i]!=table[1][i])
			return false;
		if(i==25)
			return true;
	}
}
int main()
{
	char s[81],t[81];
	int table[2][26];
	cin>>s>>t;
	memset(table,0,52*sizeof(int));
	if(strlen(s)!=strlen(t))
		cout<<"N";
	else
	{
		processStr(s,table[0]);
		processStr(t,table[1]);
		if(compareStr(table))
			cout<<"Y";
		else
			cout<<"N";
	}
	return 0;
}
