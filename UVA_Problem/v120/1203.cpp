#include<stdio.h>
#include<queue>
#include<string.h>
#include<functional>
#include<utility>
using namespace std;


struct priority1203
{
    int qNum;
    int period;
    int qp;
    bool operator < (const priority1203& th) const
    {
            return period > th.period;
    }
     bool operator >= (const priority1203& th) const
    {
            return qNum > th.qNum;
    }
};

int main()
{
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    char str[10];
    int qNum, period,k;
    freopen("1203.txt","rt",stdin);
    while(scanf("%s",str) == 1)
    {
        priority1203 p12;
        if(!strcmp("Register",str))
        {
            scanf("%d %d",&qNum,&period);
            pq.push(pair<int, pair<int, int>>(period, pair<int,int>(qNum,period)));
        }
        else
        {
            scanf("%d",&k);

            for(int i = 0; i < k; i++)
            {
                pair<int, pair<int, int>> pr;
                pr = pq.top();
                printf("%d\n",pr.second);
                pq.pop();
                pr.first += pr.second.second;
                pq.push(pr);
            }
            for(int j = 0; j < pq.size(); j++)
            {
                pq.pop();
            }
        }
    }
    return 0;
}
