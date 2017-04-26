#include<iostream>
using namespace std;
typedef struct
{
    int i;
    int xi;
} ST;
void sort(ST *thr,int n) //排序
{
    int i,j,min;
    ST temp;
    for(i=1; i<n; i++)
    {
        min=i;
        for(j=i+1; j<=n; j++)
            if(thr[j].xi<thr[min].xi)min=j;
        temp=thr[i];
        thr[i]=thr[min];
        thr[min]=temp;
    }
}
void display1(ST &thr) //执行一次某个线程并将其xi-1
{
    cout<<thr.i<<" ";
    thr.xi--;
}
void display2(ST *thr,int i,int n) //按顺序执行完i-n的线程数
{
    int j;
    for(i; i<=n; i++)
    {
        for(j=0; j<thr[i].xi; j++)
            cout<<thr[i].i<<" ";
    }
}
int main()
{
    ST thr[101],temp;
    int n,w,max=0,i,j;
    cin>>n>>w;
    w*=2;               //w扩大两倍方便计算
    for(i=1; i<=n; i++) //读取数据保存在结构体中 保存线程下标i以及执行次数val
    {
        cin>>thr[i].xi;
        thr[i].xi*=2;   //乘以2 因为循环一次要执行两次i
        thr[i].i=i;  //保存线程号
        max+=thr[i].xi; //统计所能计算的最大数
    }
    sort(thr,n); //按照线程执行次数从小到大排序
    if(w>=1&&w<=max)
    {
        if(n==1)    //当n=1是一种特殊情况要分开讨论
        {
            if(w==max)
            {
                cout<<"Yes"<<endl;
                display2(thr,1,1);
            }
            else cout<<"No";
        }
        else
        {
            if(w<=thr[1].xi)  //这里有两种情况如果w<最小线程执行次数的话要用后一个线程来消磨最小线程从而得到更小的Y值
            {
                if(w==thr[1].xi&&w==2) //因为消磨最小也要执行两次所以当w=1(本身扩大两倍)也是一种特殊情况
                {
                    cout<<"Yes"<<endl;
                    display1(thr[1]);
                    display2(thr,2,n);
                    display1(thr[1]);
                }
                else if(w>2)
                {
                    cout<<"Yes"<<endl;
                    display1(thr[2]); //执行一次线程2用于保存Y值方便消磨一次线程1
                    j=thr[1].xi-w+2;  //要加个2因为后面消磨之后会剩下一个1
                    while(j--)
                        display1(thr[1]); //消磨掉多余的执行次数
                    display1(thr[2]); //因为只执行过一次thr2所以xi=y=0 这里再执行一次则y=xi+1 所以不管上面怎么运行，运行完这句之后y=1上面运行值被重置
                    display1(thr[1]); //再执行一次thr1则将Xi的值重置为第二次运行的值xi=y=1这就是为什么要多消磨一次的原因了
                    display2(thr,2,n);//按顺序显示i-n剩余的线程数
                    display2(thr,1,1);

                }
                else cout<<"No";
            }
            else
            {
                cout<<"Yes"<<endl;
                max=0;
                for(i=1; i<=n; i++)
                {
                    max+=thr[i].xi;
                    if(w<max)break;
                }
                if(i>n) //i>n的话说明刚好所以都包括
                {
                    display2(thr,1,n);
                }
                else
                {
                    display1(thr[1]);
                    j=max-w;
                    while(j--)display1(thr[i]);
                    display2(thr,i+1,n);
                    display2(thr,1,i);
                }
            }
        }
    }
    else cout<<"No";
    return 0;
}
