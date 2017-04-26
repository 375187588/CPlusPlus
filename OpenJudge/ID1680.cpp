#include<iostream>

#include<string>

using namespace std;

int main()

{

    int n,i,j,o,k,m,p;
    string a,b,c;

    cin>>n;

    for(i=0; i<n; i++)
    {

        cin>>a>>b;

        m=a.length();

        for(j=1,o=0; j<=m; j++)

            for(k=0; k<=m-j; k++)
            {
                c=a.substr(k,j);
                if(p=b.find(c)!=string::npos)
                    o=j;
            }
        cout<<o<<endl;
    }

    return 0;

}
