#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    short N,M,P,i,j;
    short character[26];
    for(i=0; i<26; ++i)
        character[i]=0;
    cin>>N>>M>>P;
    for(i=0; i<N; ++i)
    {
        char str[11];
        cin>>str;
        for(j=0; str[j]!='\0'; ++j)
            character[str[j]-'A']++;
    }
    for(i=0; i<P; ++i)
    {
        char str[101];
        cin>>str;
        for(j=0; str[j]!='\0'; ++j)
            character[str[j]-'A']--;
    }
    for(i=0; i<26; i++)
    {
        if(character[i]!=0)
            while(character[i]--)
                cout<<(char)(i+'A');
    }
    return 0;
}
