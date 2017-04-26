#include <math.h>
#include <stdlib.h>
#include <iostream>
#include<memory.h>
using namespace std;

int ary[3000][3];
int m,n,t;

int Compare(const void* a,const void* b)
{
    return *(int*)b - *(int*)a;
}


int main()
{
    int count;
    cin>>count;
    while (count--)
    {
        memset(ary,0,3000*3*sizeof(int));
        cin>>m>>n>>t;
        int max = 0,r = -1,l = 0,s = 0;
        int index = 0;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                int temp;
                cin>>temp;
                if (temp)
                {
                    ary[index][0] = temp;
                    ary[index][1] = i;
                    ary[index][2] = j;
                    index++;
                }
            }
        }

        qsort(ary[0],index,3*sizeof(int),Compare);

        int a,b;
        a = b = 0;
        m = 0;

        for (int i=0; i<index; i++)
        {
            a = ary[i][1];
            b = ary[i][2];
            if (r==-1)
            {
                if (2*abs(a-r)+1<=t)
                {
                    s += abs(a-r)+1;
                    r = a;
                    l = b;
                    max += ary[i][0];
                }
                else
                    break;
            }
            else
            {
                if (s+1+abs(a-r)+abs(b-l)+a+1<=t)
                {
                    s += abs(a-r)+abs(b-l)+1;
                    r = a;
                    l = b;
                    max += ary[i][0];
                }
                else
                    break;
            }
        }
        cout<<max<<endl;
    }

    return 0;
}
