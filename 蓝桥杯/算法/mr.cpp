#include<iostream>
using namespace std;
typedef struct
{
    int i;
    int xi;
} ST;
void sort(ST *thr,int n) //����
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
void display1(ST &thr) //ִ��һ��ĳ���̲߳�����xi-1
{
    cout<<thr.i<<" ";
    thr.xi--;
}
void display2(ST *thr,int i,int n) //��˳��ִ����i-n���߳���
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
    w*=2;               //w���������������
    for(i=1; i<=n; i++) //��ȡ���ݱ����ڽṹ���� �����߳��±�i�Լ�ִ�д���val
    {
        cin>>thr[i].xi;
        thr[i].xi*=2;   //����2 ��Ϊѭ��һ��Ҫִ������i
        thr[i].i=i;  //�����̺߳�
        max+=thr[i].xi; //ͳ�����ܼ���������
    }
    sort(thr,n); //�����߳�ִ�д�����С��������
    if(w>=1&&w<=max)
    {
        if(n==1)    //��n=1��һ���������Ҫ�ֿ�����
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
            if(w<=thr[1].xi)  //����������������w<��С�߳�ִ�д����Ļ�Ҫ�ú�һ���߳�����ĥ��С�̴߳Ӷ��õ���С��Yֵ
            {
                if(w==thr[1].xi&&w==2) //��Ϊ��ĥ��СҲҪִ���������Ե�w=1(������������)Ҳ��һ���������
                {
                    cout<<"Yes"<<endl;
                    display1(thr[1]);
                    display2(thr,2,n);
                    display1(thr[1]);
                }
                else if(w>2)
                {
                    cout<<"Yes"<<endl;
                    display1(thr[2]); //ִ��һ���߳�2���ڱ���Yֵ������ĥһ���߳�1
                    j=thr[1].xi-w+2;  //Ҫ�Ӹ�2��Ϊ������ĥ֮���ʣ��һ��1
                    while(j--)
                        display1(thr[1]); //��ĥ�������ִ�д���
                    display1(thr[2]); //��Ϊִֻ�й�һ��thr2����xi=y=0 ������ִ��һ����y=xi+1 ���Բ���������ô���У����������֮��y=1��������ֵ������
                    display1(thr[1]); //��ִ��һ��thr1��Xi��ֵ����Ϊ�ڶ������е�ֵxi=y=1�����ΪʲôҪ����ĥһ�ε�ԭ����
                    display2(thr,2,n);//��˳����ʾi-nʣ����߳���
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
                if(i>n) //i>n�Ļ�˵���պ����Զ�����
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
