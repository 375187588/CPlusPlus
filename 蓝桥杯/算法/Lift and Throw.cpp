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
        //a[i] == 1 || a[i] == 3（未进行移动且不可抛出）
        if ((per[i].sts&1)&&!(per[i].sts&4))
        {
            for (j=1;j<= per[i].mov;j++)                         //移动
            {
                per[i].pos+=j;                                      //a[i]向前移动j
                per[i].sts^=1;                                      //已移动
                if (near(per[i].pos)||j==per[i].mov)                    //如果a[i]移动后的位置旁边有人或者移动距离达到上限
                {
                    farthestDfs(d+1);
                }
                per[i].pos-=j;                                      //归位
                per[i].pos-=j;                                      //a[i]向后移动j
                if (per[i].pos>=0&&(near(per[i].pos)||j==per[i].mov))                   //如果a[i]移动后的位置旁边有人或者移动距离达到上限
                {
                    farthestDfs(d+1);
                }
                per[i].pos+=j;                                      //归位
                per[i].sts^=1;                                      //还原为未移动
            }
        }
        //a[i] == 2 || a[i] == 3 || a[i] == 5（未进行举起）
        if (per[i].sts&2)
        {
            for (j=0;j<3;j++)                            //举起
            {
                if (i!=j&&per[j].ava&&per[i].thr>0)                //是否可以进行操作
                {
                    if (per[i].pos==per[j].pos+1||per[j].pos==per[i].pos+1)   //a[i]附近是否有人
                    {
                        per[j].ava=0;                               //即将举起（抛出）j，抛出前将j是否可操作标记变更为否
                        per[i].sts^=2;                              //已举起
                        per[i].sts^=4;                              //可抛出
                        per[i].up=j;                               //记录a[i]举起（抛出）了j
                        e=per[j].pos;                               //记录a[j]的举起前位置
                        per[j].pos=per[i].pos;                             //a[j]（被举起）的位置定为负数，只作用于下一层递归时的取最远位置的循环
                        farthestDfs(d+1);
                        per[j].pos=e;                               //归位
                        per[j].ava=1;                               //还原为可以进行操作
                        per[i].sts^=2;                              //还原为未举起
                        per[i].sts^=4;                              //还原为不可抛出
                    }
                }
            }
        }
        //a[i] == 4 || a[i] == 5（可抛出）
        if (per[i].sts&4)
        {
            for (j=1;j<=per[i].thr;j++)                         //抛出
            {
                per[per[i].up].ava=1;                                    //变更a[j]为可操作（以下a[j]指a[i]所举起的人）
                per[i].sts^=4;                                      //不可抛出
                e=per[per[i].up].pos;                                    //记录a[j]被举起前位置
                per[per[i].up].pos=per[i].pos+j;                             //抛出a[j]，并更新a[j]位置
                if (near(per[per[i].up].pos)||j==per[i].thr)                 //如果a[j]被抛出后的位置旁边有人或者抛出距离达到上限
                {
                    farthestDfs(d+1);
                }
                per[per[i].up].pos-=j;                                   //归位
                per[per[i].up].pos-=j;                                   //a[j]向后抛出j
                if (per[per[i].up].pos>=0&&(near(per[per[i].up].pos)||j==per[i].thr))                //如果a[j]被抛出后的位置旁边有人或者抛出距离达到上限
                {
                    farthestDfs(d+1);
                }
                per[per[i].up].pos=e;                                    //还原a[j]为未举起前的位置
                per[i].sts^=4;                                      //还原a[j]为可抛出
                per[per[i].up].ava=0;                                    //还原a[j]为不可操作
            }
        }
    }
    return ;
}

int main()
{

    //键入每个人的信息
    for (int i=0;i<3;i++)
    {
        cin>>per[i].pos>>per[i].mov>>per[i].thr;
    }
    //深度优先遍历
    farthestDfs(1);
    //输出最远距离
    cout<<ans;
    return 0;
}
