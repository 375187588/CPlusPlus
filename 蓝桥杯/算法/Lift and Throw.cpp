#include <iostream>
using namespace std;
struct person
{
    int pos;
    int mov;
    int thr;
    bool ava;
    int up;
    int sts;
    person(){ava=1,up=-1;sts=3;};
} per[3];
int ans = 0;
bool near(int s)
{
    for (int i=0;i<3;i++)
    {
        if (s==per[i].pos+1||s==per[i].pos-1)
        {
            return 1;
        }
    }
    return 0;
}
void farthestDfs(int d)
{
    int i, j , e = 0;
    for (i=0;i<3;i++)
    {
        ans = ans>per[i].pos?ans:per[i].pos;
    }
    for (i=0;i<3;i++)
    {
        if (!per[i].ava)
        {
            continue;
        }
        //a[i] == 1 || a[i] == 3��δ�����ƶ��Ҳ����׳���
        if ((per[i].sts&1)&&!(per[i].sts&4))
        {
            for (j=1;j<= per[i].mov;j++)                         //�ƶ�
            {
                per[i].pos+=j;                                      //a[i]��ǰ�ƶ�j
                per[i].sts^=1;                                      //���ƶ�
                if (near(per[i].pos)||j==per[i].mov)                    //���a[i]�ƶ����λ���Ա����˻����ƶ�����ﵽ����
                {
                    farthestDfs(d+1);
                }
                per[i].pos-=j;                                      //��λ
                per[i].pos-=j;                                      //a[i]����ƶ�j
                if (per[i].pos>=0&&(near(per[i].pos)||j==per[i].mov))                   //���a[i]�ƶ����λ���Ա����˻����ƶ�����ﵽ����
                {
                    farthestDfs(d+1);
                }
                per[i].pos+=j;                                      //��λ
                per[i].sts^=1;                                      //��ԭΪδ�ƶ�
            }
        }
        //a[i] == 2 || a[i] == 3 || a[i] == 5��δ���о���
        if (per[i].sts&2)
        {
            for (j=0;j<3;j++)                            //����
            {
                if (i!=j&&per[j].ava&&per[i].thr>0)                //�Ƿ���Խ��в���
                {
                    if (per[i].pos==per[j].pos+1||per[j].pos==per[i].pos+1)   //a[i]�����Ƿ�����
                    {
                        per[j].ava=0;                               //���������׳���j���׳�ǰ��j�Ƿ�ɲ�����Ǳ��Ϊ��
                        per[i].sts^=2;                              //�Ѿ���
                        per[i].sts^=4;                              //���׳�
                        per[i].up=j;                               //��¼a[i]�����׳�����j
                        e=per[j].pos;                               //��¼a[j]�ľ���ǰλ��
                        per[j].pos=per[i].pos;                             //a[j]�������𣩵�λ�ö�Ϊ������ֻ��������һ��ݹ�ʱ��ȡ��Զλ�õ�ѭ��
                        farthestDfs(d+1);
                        per[j].pos=e;                               //��λ
                        per[j].ava=1;                               //��ԭΪ���Խ��в���
                        per[i].sts^=2;                              //��ԭΪδ����
                        per[i].sts^=4;                              //��ԭΪ�����׳�
                    }
                }
            }
        }
        //a[i] == 4 || a[i] == 5�����׳���
        if (per[i].sts&4)
        {
            for (j=1;j<=per[i].thr;j++)                         //�׳�
            {
                per[per[i].up].ava=1;                                    //���a[j]Ϊ�ɲ���������a[j]ָa[i]��������ˣ�
                per[i].sts^=4;                                      //�����׳�
                e=per[per[i].up].pos;                                    //��¼a[j]������ǰλ��
                per[per[i].up].pos=per[i].pos+j;                             //�׳�a[j]��������a[j]λ��
                if (near(per[per[i].up].pos)||j==per[i].thr)                 //���a[j]���׳����λ���Ա����˻����׳�����ﵽ����
                {
                    farthestDfs(d+1);
                }
                per[per[i].up].pos-=j;                                   //��λ
                per[per[i].up].pos-=j;                                   //a[j]����׳�j
                if (per[per[i].up].pos>=0&&(near(per[per[i].up].pos)||j==per[i].thr))                //���a[j]���׳����λ���Ա����˻����׳�����ﵽ����
                {
                    farthestDfs(d+1);
                }
                per[per[i].up].pos=e;                                    //��ԭa[j]Ϊδ����ǰ��λ��
                per[i].sts^=4;                                      //��ԭa[j]Ϊ���׳�
                per[per[i].up].ava=0;                                    //��ԭa[j]Ϊ���ɲ���
            }
        }
    }
    return ;
}

int main()
{

    //����ÿ���˵���Ϣ
    for (int i=0;i<3;i++)
    {
        cin>>per[i].pos>>per[i].mov>>per[i].thr;
    }
    //������ȱ���
    farthestDfs(1);
    //�����Զ����
    cout<<ans;
    return 0;
}
