#include<iostream>
using namespace std;
int main()
{
    int i,j,n,a,b,c,m,o,p,q,r,k,g,f,e;
    cin>>j;
    for(i=0; i<j; i++)
    {
        cin>>a>>b>>c;
        for(g=2,k=0; g<=16; g++)
        {
            m=a,n=b,o=c,p=0,q=0,r=0;
            for(f=0,e=1; o>0; f++)
            {
                if(m%10>=g||n%10>=g||o%10>=g)
                {
                    p=0,q=0,r=0;
                    break;
                }
                p+=(m%10)*e,m/=10,q+=(n%10)*e,n/=10,r+=(o%10)*e,o/=10;
                e*=g;
            }
            if(p!=0||q!=0||r!=0)
                if(p*q==r)
                {
                    cout<<g<<endl;
                    k++;
                    break;
                }
        }
        if(k==0)
            cout<<0<<endl;
    }
    return 0;
}
