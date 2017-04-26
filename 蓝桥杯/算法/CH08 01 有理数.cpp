#include<iostream>
#include<algorithm>
#include<bitset>
using namespace std;
class zrf_Ratio
{
public:
    int numerator,denominator;
    friend ostream &operator<<(ostream &os, const zrf_Ratio &zrf);
    friend istream &operator<<(istream &is, zrf_Ratio &zrf);
    bool operator==(const zrf_Ratio &zrf);
    bool operator<(const zrf_Ratio &zrf);
};
bool zrf_Ratio::operator==(const zrf_Ratio &zrf)
{
    return this->numerator*zrf.denominator==this->denominator*zrf.numerator;
}
bool zrf_Ratio::operator<(const zrf_Ratio &zrf)
{
    return this->numerator*zrf.denominator<this->denominator*zrf.numerator;
}
istream &operator>>(istream &is,zrf_Ratio &zrf)
{
    is>>zrf.numerator>>zrf.denominator;
    int temp=zrf.numerator;
    int temp0=~(zrf.numerator^zrf.denominator);
    for(int bit=31;bit>=0;bit--,temp0=temp0>>1)
    {
        if(!(temp0&1))
        {
            temp=temp<<bit;
            temp=temp>>bit;
            break;
        }
    }
    temp=temp?temp:1;
    zrf.numerator/=temp,zrf.denominator/=temp;
    return is;
}
ostream &operator<<(ostream &os, const zrf_Ratio &zrf)
{
    os<<zrf.numerator<<"/"<<zrf.denominator;
    return os;
}
int main()
{
    zrf_Ratio zrf,ssh;
    cin>>zrf>>ssh;
    cout<<"zrf is:"<<zrf<<"; ssh is:"<<ssh<<endl;
    cout<<"(zrf==ssh) is:"<<(zrf==ssh)<<"; (zrf<ssh) is:"<<(zrf<ssh);
}


