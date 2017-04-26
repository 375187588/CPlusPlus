#include<iostream>
#include<cstring>
using namespace std;
int s;
void prt(char a,char b,char c)
{
    int i;
    cout<<a;
    for(i=0; i<s; i++)
        cout<<b;
    cout<<c;
}
int main()
{
    int y,i,j;
    char n[9];
    while(cin>>s>>n&&s!=0)
    {
        y=strlen(n);
        for(i=0; i<y; i++)
        {
            if(n[i]=='1'||n[i]=='4')
                prt(' ',' ',' ');
            else
                prt(' ','-',' ');
            cout<<' ';
        }
        cout<<endl;
        for(i=0; i<s; i++)
        {
            for(j=0; j<y; j++)
            {
                if(n[j]=='5'||n[j]=='6')
                    prt('|',' ',' ');
                else if(n[j]=='1'||n[j]=='2'||n[j]=='3'||n[j]=='7')
                    prt(' ',' ','|');
                else
                    prt('|',' ','|');
                cout<<" ";
            }
            cout<<endl;
        }
        for(i=0; i<y; i++)
        {
            if(n[i]=='1'||n[i]=='7'||n[i]=='0')
                prt(' ',' ',' ');
            else
                prt(' ','-',' ');
            cout<<' ';
        }
        cout<<endl;
        for(i=0; i<s; i++)
        {
            for(j=0; j<y; j++)
            {
                if(n[j]=='2')
                    prt('|',' ',' ');
                else if(n[j]=='0'||n[j]=='6'||n[j]=='8')
                    prt('|',' ','|');
                else
                    prt(' ',' ','|');
                cout<<' ';
            }
            cout<<endl;
        }
        for(i=0; i<y; i++)
        {
            if(n[i]=='1'||n[i]=='7'||n[i]=='4')
                prt(' ',' ',' ');
            else
                prt(' ','-',' ');
            cout<<' ';
        }
        cout<<endl<<endl;
    }
    return 0;
}
