#include<iostream>
#include<stack>
#include<cstring>
#include<cstdio>
#include<list>
using namespace std;
class Element
{
public:
    bool isFigure;
    char op;
    Element(){}
    Element(char c)
    {
        op=c;
        isFigure=0;
    }
    int calculate(Element data1,Element data2)
    {
        switch(op)
        {
        case '+':
            {
                return data1.value+data2.value;
            }
        case '-':
            {
                return data1.value-data2.value;
            }
        case '*':
            {
                return data1.value*data2.value;
            }
        case '/':
            {
                return data1.value/data2.value;
            }
        };
    }
    int value;
    Element(int v)
    {
        value=v;
        isFigure=1;
    }
    friend ostream &operator<<(ostream &os,const Element &e);
    friend istream &operator<<(istream &is,Element &e);
};
ostream &operator<<(ostream &os,const Element &e)
{
    if(e.isFigure)os<<e.value;
    else os<<e.op;
    return os;
}
istream &operator<<(istream &is,Element &e)
{

}
int getProp(char c)
{
    if(c=='+'||c=='-')return 1;
    if(c=='*'||c=='/')return 2;
}
int transformString(list<Element> &expression,char *str,int strLength,int beginning)
{
    int tempFig;
    int expLength=expression.size();
    bool isFrontFig=1;
    char *tempStr;
    tempStr=new char[10];
    int strIt=0;
    int symbol=1;
    stack<char> s;
    for(;beginning<strLength;beginning++)
    {
        char temp=str[beginning];
        if(temp=='+'||temp=='-'||temp=='*'||temp=='/')
        {
            if(temp=='-'&&(beginning==0||str[beginning-1]=='('))
                symbol=-1;
            else
            {
                int prop=getProp(temp);
                while(s.size()&&getProp(s.top())>=prop&&s.top()!='(')
                {
                    Element *e=new Element(s.top());
                    s.pop();
                    expression.push_back(*e);
                }
                s.push(temp);
            }
        }
        else if(temp>='0'&&temp<='9')
        {
            tempStr[strIt++]=temp;
            if(beginning+1==strLength||str[beginning+1]<'0'||str[beginning+1]>'9')
            {
                tempStr[strIt]=0;
                sscanf(tempStr,"%d",&tempFig);
                tempFig*=symbol;
                symbol=1;
                Element *e=new Element(tempFig);
                expression.push_back(*e);
                strIt=0;
            }
        }
        else if(temp=='(')
            s.push(temp);
        else if(temp==')')
        {
            while(s.top()!='(')
            {
                Element *e=new Element(s.top());
                s.pop();
                expression.push_back(*e);
            }
            s.pop();
        }
    }
    while(s.size())
    {
        Element *e=new Element(s.top());
        s.pop();
        expression.push_back(*e);
    }
}
int calculate(list<Element> &expression)
{
    stack<Element> s;
    for(list<Element>::iterator it=expression.begin();it!=expression.end();it++)
    {
        if(it->isFigure) s.push(*it);
        else
        {
            Element e0=s.top();
            s.pop();
            Element e1=s.top();
            s.pop();
            Element *e=new Element(it->calculate(e1,e0));
            s.push(*e);
        }
    }
    return s.top().value;
}
int main()
{
    char str[1000];
    cin>>str;
    int strlength=strlen(str);
    list<Element> expression;
    transformString(expression,str,strlength,0);
    cout<<calculate(expression);
}
