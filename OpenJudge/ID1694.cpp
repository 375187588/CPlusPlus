#include<iostream>
#include<cstring>
using namespace std;
char a[3][7],b[3][7],c[3][5];
int l(char z)
{
    int i;
    for(i=0; i<3; i++)
        switch(c[i][0])
        {
        case'e':
            if(strchr(a[i],z)!=NULL||strchr(b[i],z)!=NULL)
                return 0;
            break;
        case'u':
            if(strchr(b[i],z)==NULL)
                return 0;
            break;
        case'd':
            if(strchr(a[i],z)==NULL)
                return 0;
            break;
        }
    return 1;
}
int h(char z)
{
    int i;
    for(i=0; i<3; i++)
        switch(c[i][0])
        {
        case'e':
            if(strchr(a[i],z)!=NULL||strchr(b[i],z)!=NULL)
                return 0;
            break;
        case'u':
            if(strchr(a[i],z)==NULL)
                return 0;
            break;
        case'd':
            if(strchr(b[i],z)==NULL)
                return 0;
            break;
        }
    return 1;
}

int main()
{
    int n,i,j;
    char d;
    cin>>n;
    for(i=0; i<n; i++)
    {
        for(j=0; j<3; j++)
            cin>>a[j]>>b[j]>>c[j];
        for(d='A'; d<'M'; d++)
        {
            if(l(d))
            {
                cout<<d<<" is the counterfeit coin and it is light."<<endl;
                break;
            }
            if(h(d))
            {
                cout<<d<<" is the counterfeit coin and it is heavy."<<endl;
                break;
            }
        }
    }
}
