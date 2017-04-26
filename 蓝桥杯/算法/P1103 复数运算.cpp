#include<iostream>
#include<iomanip>
using namespace std;
class complexNum
{
public:
    double r,i;
    complexNum(){};
    complexNum(double r,double i);
    friend ostream &operator<<(ostream &os,const complexNum &c);
    friend istream &operator>>(istream &is,complexNum &c);
    complexNum &operator+(const complexNum&c);
    complexNum &operator-(const complexNum&c);
    complexNum &operator*(const complexNum&c);
    complexNum &operator/(const complexNum&c);
};
complexNum::complexNum(double r,double i)
{
    this->r=r,this->i=i;
}
ostream &operator<<(ostream &os,const complexNum &c)
{
    os<<setprecision(2)<<setiosflags(ios::fixed)<<c.r<<"+"<<setprecision(2)<<setiosflags(ios::fixed)<<c.i<<"i";
}
istream &operator>>(istream &is,complexNum &c)
{
    cin>>c.r>>c.i;
}
complexNum &complexNum::operator+(const complexNum &c)
{
    complexNum *c_=new complexNum(r+c.r,i+c.i);
    return *c_;
}
complexNum &complexNum::operator-(const complexNum&c)
{
    complexNum *c_=new complexNum(r-c.r,i-c.i);
    return *c_;
}
complexNum &complexNum::operator*(const complexNum&c)
{
    complexNum *c_=new complexNum(r*c.r-i*c.i,r*c.i+i*c.r);
    return *c_;
}
complexNum &complexNum::operator/(const complexNum&c)
{
    double den=c.r*c.r+c.i*c.i;
    complexNum *c_=new complexNum((r*c.r+i*c.i)/den,(i*c.r-r*c.i)/den);
    return *c_;
}
int main()
{
    complexNum c,c_;
    char op;
    cin>>op>>c>>c_;
    switch(op)
    {
    case '+':
        cout<<c+c_;
        break;
    case '-':
        cout<<c-c_;
        break;
    case '*':
        cout<<c*c_;
        break;
    case '/':
        cout<<c/c_;
        break;
    }
}
