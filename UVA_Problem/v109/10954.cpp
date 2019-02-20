#include<bits/stdc++.h>
#include<vector>
using namespace std;

struct compareFunc
{
    bool operator()(const int &a, const int &b)
    {
        return a > b;
    }
};

int main()
{
    int testCase,i,j,n;
    priority_queue<int, vector<int>, compareFunc> pq;
    freopen("10954.txt", "rt",stdin);
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        for(i = 0; i < n; i++)
        {
            scanf("%d",&j);
            pq.push(j);
        }


        int cost1 = 0;
        int cost2 = 0;
        int cost = 0;
        int sum = 0;

        while(!pq.empty())
        {
            cost1 = pq.top();
            pq.pop();
            if(!pq.empty())
            {
                cost2 = pq.top();
                pq.pop();
            }
            else
            {
                cost2 = 0;
                break;
            }
            cost = cost1 + cost2;
            pq.push(cost);
            sum += cost;

        }
        printf("%d\n",sum);

    }
    return 0;
}
